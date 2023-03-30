/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:37:14 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/27 11:46:50 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

char	*get_heredoc(char *heredoc, char *line)
{
	char	*temp;

	if (line)
	{
		if (heredoc != NULL)
		{
			temp = ft_strdup(heredoc);
			free(heredoc);
			heredoc = ft_strjoin(temp, line);
			free(temp);
		}
		else
			heredoc = ft_strdup(line);
		free(line);
	}
	return (heredoc);
}

void	here_doc(char *limiter, int fd[2])
{
	char	*line;
	char	*here_doc;

	here_doc = NULL;
	while (1)
	{
		ft_printf_fd(STDOUT_FILENO, "pipe heredoc> ");
		line = get_next_line(STDIN_FILENO);
		if (line && ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
			break ;
		else
			here_doc = get_heredoc(here_doc, line);
	}
	free(line);
	if (write(fd[1], NULL, 0) < 0)
	{
		ft_printf_fd(2, "can't write");
		return ;
	}
	write(fd[1], here_doc, ft_strlen(here_doc));
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
}