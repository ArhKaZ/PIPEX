/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:02:23 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/14 16:40:19 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*get_full_path(char *path, char *command)
{
	char	*full_path;
	char	*temp;

	full_path = ft_strjoin(path, "/");
	temp = ft_strdup(full_path);
	free(full_path);
	full_path = ft_strjoin(temp, command);
	free(temp);
	return (full_path);
}

char	**get_path(char **envp)
{
	int		i;
	char	**path;

	i = 0;
	while(envp[i] != NULL)
	{
		if (envp[i][0] == 'P' && ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_split(envp[i] + 5, ':');
			break ;
		}
		i++;
	}
	return (path);
}

char	*get_path_command(char *command, char **envp)
{
	char	**path;
	int		i;
	int		exist;
	char	*full_path;

	i = 0;
	path = get_path(envp);
	if (path == NULL)
		return (false);
	while (path[i])
	{
		if (access(get_full_path(path[i], command), F_OK) != -1)
		{
			full_path = get_full_path(path[i], command);
			free_char_tab(path);
			return (full_path);
		}
		i++;
	}
	free_char_tab(path);
	return (NULL);
}
