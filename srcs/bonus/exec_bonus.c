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

void	exec_cmd_n(t_pipe *cmd, int nb)
{
	if (cmd->is_hd == false)
	{
		if (nb == 0 && cmd->infile > 0)
			dup2(cmd->infile, STDIN_FILENO);
		close(cmd->infile);
	}
	if (nb == cmd->nb_exec - 1)
	{
		dup2(cmd->outfile, STDOUT_FILENO);
		close(cmd->outfile);
	}
	if (cmd->is_hd == false)
	{
		execve(cmd->cmd[nb][0], cmd->cmd[nb], NULL);
		perror(cmd->cmd[nb][0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		execve(cmd->cmd[nb - 1][0], cmd->cmd[nb - 1], NULL);
		perror(cmd->cmd[nb - 1][0]);
		exit(EXIT_FAILURE);
	}
}

void	child_proc(t_pipe *pipex, int fd[2], int last, char **cmd)
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
	execve(cmd[0], cmd, pipex->envp);
	perror(cmd[0]);
	exit(EXIT_FAILURE);
}

void	exec_pipex(t_pipe *pipex, char **cmd, int last)
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
		child_proc(pipex, fd, last, cmd);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
}
