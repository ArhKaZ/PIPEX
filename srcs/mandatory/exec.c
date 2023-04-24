/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:46:20 by syluiset          #+#    #+#             */
/*   Updated: 2023/04/24 17:14:40 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd1(t_pipe *cmd)
{
	if (cmd->cmd1[0] == NULL)
		return (free_cmd(cmd), exit(EXIT_FAILURE));
	if (cmd->infile < 0)
		return (free_cmd(cmd), exit(EXIT_FAILURE));
	if (dup2(cmd->infile, STDIN_FILENO) == -1)
		return (free_cmd(cmd), exit(EXIT_FAILURE));
	close(cmd->infile);
	if (dup2(cmd->fd[1], STDOUT_FILENO) == -1)
		return (free_cmd(cmd), exit(EXIT_FAILURE));
	close(cmd->fd[0]);
	close(cmd->fd[1]);
	execve(cmd->cmd1[0], cmd->cmd1, NULL);
	perror(cmd->cmd1[0]);
	exit(EXIT_FAILURE);
}

void	exec_cmd2(t_pipe *cmd)
{
	if (cmd->cmd2[0] == NULL)
		return (free_cmd(cmd), exit(EXIT_FAILURE));
	if (cmd->outfile < 0)
		return (free_cmd(cmd), exit(EXIT_FAILURE));
	if (dup2(cmd->fd[0], STDIN_FILENO) == -1)
		return (free_cmd(cmd), exit(EXIT_FAILURE));
	close(cmd->fd[0]);
	if (dup2(cmd->outfile, STDOUT_FILENO) == -1)
		return (free_cmd(cmd), exit(EXIT_FAILURE));
	close(cmd->outfile);
	execve(cmd->cmd2[0], cmd->cmd2, NULL);
	perror(cmd->cmd2[0]);
	exit(EXIT_FAILURE);
}
