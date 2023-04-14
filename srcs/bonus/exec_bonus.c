/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:46:20 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/27 16:39:45 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child_proc(t_pipe *pipex, int fd[2], int cases, char **cmd)
{
	close(fd[0]);
	if (cases == 0 && pipex->should_frst == false)
	{
		close(fd[1]);
		exit(EXIT_FAILURE);
	}
	if (cases == 1) {
		if (pipex->should_last == false)
		{
			close(fd[1]);
			exit(EXIT_FAILURE);
		}
		else
		{
			dup2(pipex->outfile, STDOUT_FILENO);
			close(pipex->outfile);
		}
	}
	else
		dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	execve(cmd[0], cmd, pipex->envp);
	perror(cmd[0]);
	exit(EXIT_FAILURE);
}

void	exec_pipex(t_pipe *pipex, char **cmd, int last, int execution)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(&fd[0]) == -1)
		return (free_pipe(pipex));
	pid = fork();
	if (pid < 0)
	{
		ft_printf_fd(STDERR_FILENO, "Error");
		return (free_pipe(pipex));
	}
	if (pid == 0)
	{
		if (execution == 0)
			child_proc(pipex, fd, 0, cmd);
		else if (last)
			child_proc(pipex, fd, 1, cmd);
		else
			child_proc(pipex, fd, 2, cmd);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
}
