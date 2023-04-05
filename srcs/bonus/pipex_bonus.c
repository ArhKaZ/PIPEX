/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:30:01 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/27 16:50:15 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exec_pipex(t_pipe *pipex, char **cmd, char **envp, int last)
{
	int	fd[2];
	pid_t	pid;

	if (pipe(&fd[0]) == -1)
		return (free_pipe(pipex));
	pid = fork();
	if (pid < 0)
	{
		ft_printf_fd(STDERR_FILENO, "Error");
		return (free_pipe(pipex));
	}
	if (pid > 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
	if (pid == 0)
	{
		close(fd[0]);
		if (!last)
			dup2(fd[1], STDOUT_FILENO);
		else
		{
			dup2(pipex->outfile, STDOUT_FILENO);
			close(pipex->outfile);
		}
		close(fd[1]);
		execve(cmd[0], cmd, envp);
	}
}

void	forking_bonus(t_pipe *pipex, char **envp)
{
	int execution;

	execution = 0;
	while (execution < pipex->nb_exec)
	{
		dprintf(2, "%d\n", execution);
		if (execution != pipex->nb_exec - 1)
			exec_pipex(pipex, pipex->cmd[execution], envp, 0);
		else
		{
			pipex->outfile = open(pipex->outfile_path,  O_WRONLY | O_CREAT | O_TRUNC, 0644);
			exec_pipex(pipex, pipex->cmd[execution], envp, 1);
		}
		execution++;
	}
	while (execution--)
		wait(NULL);
}

char	***get_all_command(char **argv, bool is_hd, int nb_ex)
{
	char ***tab;
	int i;
	int count;

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
	int infile;

	infile = 0;
	infile = open(argv[1], O_RDONLY, 0444);
	if (infile == -1)
		return (perror(argv[1]), -1);
	return (infile);
}

t_pipe	*parsing_bonus(int argc, char **argv, char **envp, bool is_hd)
{
	t_pipe	*pipe;
	int		i;

	i = 0;
	pipe = malloc(sizeof(t_pipe));
	pipe->is_hd = is_hd;
	if (is_hd == false)
		pipe->nb_exec = argc - 3;
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
		pipe->cmd[i][0] = get_path_command(pipe->cmd[i][0], envp);
		if (pipe->cmd[i][0] == NULL)
			return (free_pipe(pipe), pipe = NULL, NULL);
		i++;
	}
	pipe->outfile_path = ft_strdup(argv[argc - 1]);
	return (pipe);
}

int main(int argc, char **argv, char **envp)
{
	t_pipe	*pipex;
	bool	is_hd;
	int		infile;

	infile = 0;
	is_hd = false;
	if (argc < 5)
		return (1);
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1]) + 1) == 0)
	{
		is_hd = true;
	}
	else
	{
		infile = open_and_pipe_bonus(argv);
		dup2(infile, STDIN_FILENO);
		close(infile);
	}
	pipex = parsing_bonus(argc, argv, envp, is_hd);
	printf("yoyo\n");
	if (is_hd == true)
		here_doc_exec(pipex);
	dprintf(2,"bloque");
	forking_bonus(pipex, envp);
	dprintf(2,"je n'y arrive jamais\n");
	free_pipe(pipex);
}
