/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:30:01 by syluiset          #+#    #+#             */
/*   Updated: 2023/04/12 00:36:27 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	forking_bonus(t_pipe *pipex)
{
	int	execution;

	execution = 0;
	while (execution < pipex->nb_exec)
	{
		if (execution != pipex->nb_exec - 1)
			exec_pipex(pipex, pipex->cmd[execution], 0);
		else
		{
			pipex->outfile = open(pipex->outfile_path,
					O_WRONLY | O_CREAT | O_TRUNC, 0644);
			exec_pipex(pipex, pipex->cmd[execution], 1);
		}
		execution++;
	}
	while (execution--)
		wait(NULL);
}

char	***get_all_command(char **argv, bool is_hd, int nb_ex)
{
	char	***tab;
	int		i;
	int		count;

	count = 0;
	if (is_hd == false)
		i = 2;
	else
		i = 3;
	tab = malloc(sizeof(char **) * (nb_ex + 1));
	if (!tab)
		return (NULL);
	while (count < nb_ex)
	{
		tab[count] = ft_split(argv[i], ' ');
		if (tab[count][0] == NULL)
		{
			free_three_char_tab(tab);
			return (ft_printf_fd(STDERR_FILENO, "permission denied:"), NULL);
		}
		i++;
		count++;
	}
	tab[count] = NULL;
	return (tab);
}

int	open_and_pipe_bonus(char **argv)
{
	int	infile;

	infile = 0;
	infile = open(argv[1], O_RDONLY, 0444);
	if (infile == -1)
		return (perror(argv[1]), -1);
	dup2(infile, STDIN_FILENO);
	close(infile);
	return (infile);
}

char	**cp_tab(char **to_cp)
{
	int		i;
	char	**cp;

	i = 0;
	while (to_cp[i])
		i++;
	cp = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (to_cp[i])
	{
		cp[i] = ft_strdup(to_cp[i]);
		i++;
	}
	cp[i] = NULL;
	return (cp);
}

t_pipe	*parsing_bonus(int argc, char **argv, char **envp, bool is_hd)
{
	t_pipe	*pipe;
	int		i;

	i = 0;
	pipe = malloc(sizeof(t_pipe));
	pipe->is_hd = is_hd;
	pipe->envp = cp_tab(envp);
	if (is_hd == false)
	{
		pipe->limiter = NULL;
		pipe->nb_exec = argc - 3;
	}
	else
	{
		pipe->limiter = ft_strjoin(argv[2], "\n");
		if (pipe->limiter == NULL)
			free_pipe(pipe);
		pipe->nb_exec = argc - 4;
	}
	pipe->cmd = get_all_command(argv, is_hd, pipe->nb_exec);
	if (pipe->cmd == NULL)
		return (free(pipe), NULL);
	while (i < pipe->nb_exec)
	{
		pipe->cmd[i][0] = get_path_command(pipe->cmd[i][0], pipe->envp);
		if (pipe->cmd[i][0] == NULL)
			return (free_pipe(pipe), pipe = NULL, NULL);
		i++;
	}
	pipe->outfile_path = ft_strdup(argv[argc - 1]);
	return (pipe);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	*pipex;
	bool	is_hd;

	is_hd = false;
	if (argc < 5)
		return (1);
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1]) + 1) == 0)
		is_hd = true;
	else
		open_and_pipe_bonus(argv);
	pipex = parsing_bonus(argc, argv, envp, is_hd);
	if (is_hd == true)
		here_doc(pipex->limiter);
	forking_bonus(pipex);
	free_pipe(pipex);
}
