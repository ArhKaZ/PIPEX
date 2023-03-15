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

#include "../include/pipex.h"

void	exec_cmd1(t_cmd *cmd)
{
	int		infile;
	//char	*cmd_name;

	infile = open(cmd->infile, O_RDONLY);
	if (infile == -1)
		return ;
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(cmd->fd[1], STDOUT_FILENO);
	close(cmd->fd[0]);
	close(cmd->fd[1]);
	//cmd_name = ft_strrchr(cmd->cmd1[0], '/');
	execve(cmd->cmd1[0], cmd->cmd1, NULL);
	perror("execve");
}

void	exec_cmd2(t_cmd *cmd)
{
	int		outfile;
	//char	*cmd_name;

	outfile = open(cmd->outfile, O_WRONLY);
	if (outfile == -1)
		return ;
	dup2(cmd->fd[0], STDIN_FILENO);
	close(cmd->fd[0]);
	close(cmd->fd[1]);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	//cmd_name = ft_strrchr(cmd->cmd2[0], '/');
	execve(cmd->cmd2[0], cmd->cmd2, NULL);
	perror("execve");
}