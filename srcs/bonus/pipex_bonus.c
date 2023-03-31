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

void	forking_bonus(t_pipe *pipex)
{
	int execution;

	execution = 0;
	pipex->fork_int = malloc(sizeof(int) * pipex->nb_exec);
	while (execution < pipex->nb_exec)
	{
		pipe(pipex->fd);
		pipex->fork_int[execution] = fork();
		if (pipex->fork_int[execution] < 0)
		{
			ft_printf_fd(STDERR_FILENO, "Error");
			return (free_pipe(pipex));
		}
		if (pipex->fork_int[execution] == 0)
		{
			dup2(pipex->fd[1], STDOUT_FILENO);
			close(pipex->fd[0]);
			close(pipex->fd[1]);
			exec_cmd_n(pipex, execution);
		}
		else
		{
			dup2(pipex->fd[0], STDIN_FILENO);
			close(pipex->fd[1]);
			close(pipex->fd[0]);
			waitpid(pipex->fork_int[execution], NULL, 0);
		}
		execution++;
	}
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
	tab = malloc(sizeof(char **) * nb_ex + 1);
	if (!tab)
		return (NULL);
	while (argv[i + 1] != NULL)
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

bool	open_and_pipe_bonus(int argc, char **argv, t_pipe *cmd, bool is_hd)
{
	if (is_hd == false)
		cmd->infile = open(argv[1], O_RDONLY, 0444);
//	else
//		cmd->infile = fd;
	if (cmd->infile == -1)
		return (perror(argv[1]), false);
	cmd->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (cmd->outfile == -1)
		return (perror(argv[argc - 1]), false);
	return (true);
}

t_pipe	*parsing_bonus(int argc, char **argv, char **envp, bool is_hd)
{
	t_pipe	*pipe;
	int		i;

	i = 0;
	pipe = malloc(sizeof(t_pipe));
	if (is_hd == false)
		pipe->nb_exec = argc - 3;
	else
		pipe->nb_exec = argc - 5;
	pipe->cmd = get_all_command(argv, is_hd, pipe->nb_exec);
	if (pipe->cmd == NULL)
		return (free(pipe), NULL);
	while (pipe->cmd[i] != NULL)
	{
		pipe->cmd[i][0] = get_path_command(pipe->cmd[i][0], envp);
		if (pipe->cmd[i][0] == NULL)
			return (free_pipe(pipe), pipe = NULL, NULL);
		i++;
	}
	if (open_and_pipe_bonus(argc, argv, pipe, is_hd) == false)
	{
		free_pipe(pipe);
		pipe = NULL;
	}
	return (pipe);
}

int main(int argc, char **argv, char **envp)
{
	t_pipe	*pipex;
	bool	is_hd;
	int 	fd0;

	fd0 = -1;
	is_hd = false;
	if (argc < 5)
		return (1);
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
	{
		fd0 = launch_here_doc(argv[2]);
		is_hd = true;
	}
	pipex = parsing_bonus(argc, argv, envp, is_hd);
	forking_bonus(pipex);
	free_pipe(pipex);
}
