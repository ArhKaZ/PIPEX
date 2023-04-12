/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:46:20 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/15 21:52:32 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd1(t_pipe *cmd)
{
	if (dup2(cmd->infile, STDIN_FILENO) == -1)
		return (free_cmd(cmd), exit(EXIT_FAILURE));
	close(cmd->infile);
	if (dup2(cmd->fd[1], STDOUT_FILENO) == -1)
		return (free_cmd(cmd), exit(EXIT_FAILURE));
	close(cmd->fd[0]);
	close(cmd->fd[1]);
	execve(cmd->cmd1[0], cmd->cmd1, NULL);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	exec_cmd2(t_pipe *cmd)
{
	if (dup2(cmd->fd[0], STDIN_FILENO) == -1)
		return (free_cmd(cmd), exit(EXIT_FAILURE));
	close(cmd->fd[0]);
	if (dup2(cmd->outfile, STDOUT_FILENO) == -1)
		return (free_cmd(cmd), exit(EXIT_FAILURE));
	close(cmd->outfile);
	execve(cmd->cmd2[0], cmd->cmd2, NULL);
	perror("execve");
	exit(EXIT_FAILURE);
}
