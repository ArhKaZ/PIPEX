/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:09:34 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/14 16:10:41 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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

void	free_cmd(t_cmd *cmd)
{
	free_char_tab(cmd->cmd1);
	free_char_tab(cmd->cmd2);
	close(cmd->infile);
	close(cmd->outfile);
	close(cmd->fd[0]);
	close(cmd->fd[1]);
	free(cmd);
}