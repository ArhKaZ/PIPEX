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

void	exec_first_cmd(t_pipe *cmd)
{

	//close_fd(cmd);
	execve(cmd->cmd[0][0], cmd->cmd[0], NULL);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	exec_cmd_n(t_pipe *cmd, int nb)
{
	if (nb == 0)
	{
		if (dup2(cmd->infile, STDIN_FILENO) == -1)
			return (free_pipe(cmd), exit(EXIT_FAILURE));
		close(cmd->infile);
	}
	if (nb == cmd->nb_exec - 1)
	{
		if (dup2(cmd->outfile, STDOUT_FILENO) == -1)
			return (free_pipe(cmd), exit(EXIT_FAILURE));
		close(cmd->outfile);
	}
	//close_fd(cmd);
	execve(cmd->cmd[nb][0], cmd->cmd[nb], NULL);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	exec_last_cmd(t_pipe *cmd, int nb)
{

	//close_fd(cmd);
	execve(cmd->cmd[nb][0], cmd->cmd[nb], NULL);
	perror("execve");
	exit(EXIT_FAILURE);
}
