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

void	here_doc(char *limiter)
{
	char	*line;
	char	*here_doc;
	char	*temp;

	line = get_next_line(STDIN_FILENO);
	while (1)
	{
		temp = ft_strdup(line);
		free(line);
		line = get_next_line(STDIN_FILENO);
		if (ft_strncmp())
	}
}