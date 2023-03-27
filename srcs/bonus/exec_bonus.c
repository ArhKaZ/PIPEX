/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:46:20 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/27 11:48:43 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exec_first_cmd(t_pipe *cmd)
{
	if (dup2(cmd->infile, STDIN_FILENO) == -1)
		return (free_pipe(cmd), exit(EXIT_FAILURE));
	close(cmd->infile);
	if (dup2(cmd->fd[0][1], STDOUT_FILENO) == -1)
		return (free_pipe(cmd), exit(EXIT_FAILURE));
	close_fd(cmd);
	execve(cmd->cmd[0][0], cmd->cmd[0], NULL);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	exec_cmd_n(t_pipe *cmd, int nb)
{
	if (dup2(cmd->fd[nb][0], STDIN_FILENO) == -1)
		return (free_pipe(cmd), exit(EXIT_FAILURE));
	if (dup2(cmd->fd[nb][1], STDOUT_FILENO) == -1)
		return (free_pipe(cmd), exit(EXIT_FAILURE));
	close_fd(cmd);
	execve(cmd->cmd[nb][0], cmd->cmd[nb], NULL);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	exec_last_cmd(t_pipe *cmd, int nb)
{
	if (dup2(cmd->fd[nb - 1][0], STDIN_FILENO) == -1)
		return (free_pipe(cmd), exit(EXIT_FAILURE));
	if (dup2(cmd->outfile, STDOUT_FILENO) == -1)
		return (free_pipe(cmd), exit(EXIT_FAILURE));
	close(cmd->outfile);
	close_fd(cmd);
	execve(cmd->cmd[nb][0], cmd->cmd[nb], NULL);
	perror("execve");
	exit(EXIT_FAILURE);
}