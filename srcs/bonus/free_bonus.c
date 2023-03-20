/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:30:24 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/20 15:30:24 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	free_three_char_tab(char ***tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			free(tab[i][j]);
			j++;
		}
		i++;
	}
	free(tab);
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

void	close_fd(t_pipe *pipe)
{
	int nb_fd;

	nb_fd = 0;
	while (nb_fd < pipe->nb_exec - 1)
	{
		close(pipe->fd[nb_fd][0]);
		close(pipe->fd[nb_fd][1]);
		free(pipe->fd[nb_fd]);
		nb_fd++;
	}
	free(pipe->fd);
}

void	free_pipe(t_pipe *pipe)
{
	free_three_char_tab(pipe->cmd);
	close(pipe->infile);
	close(pipe->outfile);
	close_fd(pipe);
	free(pipe->fork_int);
	free(pipe);
}
