/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:02:23 by syluiset          #+#    #+#             */
/*   Updated: 2023/04/20 13:17:34 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

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
	while (envp[i] != NULL)
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

char	*find_right_path(char *command, char **path)
{
	char	*full_path;
	int		i;

	i = 0;
	if (ft_strncmp(command, "/", 1) == 0)
	{
		if (access(command, F_OK | X_OK) != -1)
		{
			free_char_tab(path);
			full_path = ft_strdup(command);
			return (full_path);
		}
	}
	while (path[i])
	{
		full_path = get_full_path(path[i], command);
		if (access(full_path, F_OK | X_OK) != -1)
		{
			free_char_tab(path);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	return (NULL);
}

char	*shell_executable(char *command, char **path)
{
	char	*full_path;

	full_path = NULL;
	full_path = find_right_path(command + 2, path);
	if (full_path == NULL)
	{
		if (access(command + 2, F_OK | X_OK) != -1)
		{
			free(full_path);
			full_path = ft_strdup(command);
		}
		if (full_path == NULL)
		{
			perror(command);
			return (NULL);
		}
	}
	return (full_path);
}

char	*get_path_command(char *command, char **envp)
{
	char	**path;
	char	*full_path;

	if (command == NULL)
		return (ft_printf_fd(2, "%s : command not found\n", command), NULL);
	path = get_path(envp);
	if (path == NULL)
		return (ft_printf_fd(STDERR_FILENO, "path not found\n"), NULL);
	if (ft_strncmp(command, "./", 2) != 0)
		full_path = find_right_path(command, path);
	else
	{
		full_path = shell_executable(command, path);
		if (full_path == NULL)
			return (free(command), NULL);
	}
	if (full_path != NULL)
	{
		free(command);
		return (full_path);
	}
	ft_printf_fd(STDERR_FILENO, "%s : command not found\n", command);
	return (free(command), free_char_tab(path), NULL);
}
