/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:30:24 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/27 11:38:15 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_three_char_tab(char ***tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j])
		{
			free(tab[i][j]);
			j++;
		}
		free(tab[i]);
		i++;
	}
}

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

void	free_pipe(t_pipe *pipe)
{
	free_three_char_tab(pipe->cmd);
	if (pipe->envp)
		free_char_tab(pipe->envp);
	if (pipe->outfile_path)
		free(pipe->outfile_path);
	free(pipe->limiter);
	close(pipe->outfile);
	free(pipe->cmd);
	free(pipe);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
}
