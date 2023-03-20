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

#include "pipex.h"

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
			return (path);
		}
		i++;
	}
	return (NULL);
}

char 	*shell_executable(char *command)
{
	if (access(command + 2, F_OK | X_OK) != -1)
		return (command);
	else
	{
		perror(command);
		return (NULL);
	}
}

char 	*find_right_path(char *command, char **path)
{
	char	*full_path;
	int 	i;

	i = 0;
	while (path[i])
	{
		full_path = get_full_path(path[i], command);
		if (access(full_path, F_OK | X_OK) != -1)
		{
			free_char_tab(path);
			free(command);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	return (NULL);
}

char	*get_path_command(char *command, char **envp)
{
	char	**path;
	char	*full_path;

	if (command == NULL)
		return (NULL);
	if (ft_strncmp(command, "./", 2) != 0)
	{
		path = get_path(envp);
		if (path == NULL)
		{
			ft_printf_fd(STDERR_FILENO, "command not found: %s\n", command);
			return (NULL);
		}
		full_path = find_right_path(command, path);
	}
	else
	{
		full_path = shell_executable(command);
		if (full_path == NULL)
			return (free(command), NULL);
	}
	if (full_path != NULL)
		return (full_path);
	ft_printf_fd(STDERR_FILENO, "command not found: %s\n", command);
	return (free(command), free_char_tab(path), NULL);
}
