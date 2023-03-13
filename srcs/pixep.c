/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:15:13 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/09 11:15:13 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	**get_path(char **envp)
{
	int		i;
	char	**path;

	i = 0;
	while(envp[i] != NULL)
	{
		if (envp[i][0] == 'P' && ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_split(envp[i], ":");
			break ;
		}
		i++;
	}
	return (path);
}

bool	verif_command(char **argv, char **envp)
{
	char **path;

	path = get_path(envp);
	if (path == NULL)
		return (false);

}

void	pipex(char **argv, char **envp)
{
	t_argu	*arg;
	int 	nb_fork;
	arg = malloc(sizeof(t_argu));
	arg->fd_files[0] = open(argv[1], O_RDONLY);
	arg->fd_files[1] = open(argv[4], O_WRONLY);
	if (arg->fd_files[0] == -1 || arg->fd_files[1] == -1)
	{
		free(arg);
		return (ft_putstr_fd("Error\nFiles don't exist", 2));
	}
	pipe(arg->fd_pipe);
	nb_fork = fork();
}

int main(int argc, char **argv, char **envp)
{
	int i = 0;
	//if (argc < 2 || argc > 5)
		//return (1);
	//pipex(argv, envp);
	while (envp[i] != NULL)
	{
		printf("%s %d\n", envp[i], i);
		i++;
	}
}