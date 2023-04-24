/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:09:34 by syluiset          #+#    #+#             */
/*   Updated: 2023/04/24 13:37:43 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_char_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_cmd(t_pipe *cmd)
{
	free_char_tab(cmd->cmd1);
	free_char_tab(cmd->cmd2);
	if (cmd->infile > 0)
		close(cmd->infile);
	if (cmd->outfile > 0)
		close(cmd->outfile);
	if (cmd->fd[0] > 0)
		close(cmd->fd[0]);
	if (cmd->fd[1] > 0)
		close(cmd->fd[1]);
	free(cmd);
}
