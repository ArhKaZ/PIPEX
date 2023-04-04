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
