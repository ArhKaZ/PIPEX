/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:15:13 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/14 16:42:34 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_cmd	get_command(char *arg)
{

}

void	pipex(char **argv, char **envp)
{
	char	**cmd1;
	char	**cmd2;
	// t_argu	*arg;
	// int 	nb_fork;
	// arg = malloc(sizeof(t_argu));
	// arg->fd_files[0] = open(argv[1], O_RDONLY);
	// arg->fd_files[1] = open(argv[4], O_WRONLY);
	// if (arg->fd_files[0] == -1 || arg->fd_files[1] == -1)
	// {
	// 	free(arg);
	// 	return (ft_putstr_fd("Error\nFiles don't exist", 2));
	// }
	// pipe(arg->fd_pipe);
	// nb_fork = fork();
	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');
	if (cmd1[0] == NULL || cmd2[0] == NULL)
		return ;
	cmd1 = get_path_command(cmd1[0], envp);
	cmd2 = get_path_command(cmd2[0], envp);
	if (cmd1[0] == NULL || cmd2[0] == NULL)
		return ;
}

int main(int argc, char **argv, char **envp)
{
	pipex(argv, envp);
	//if (argc < 2 || argc > 5)
		//return (1);
	//pipex(argv, envp);
	// int fd = access("sample.txt", F_OK);
    // if(fd == -1){
    //         printf("Error Number : %d\n", errno);
    //     perror("Error Description:");
    // }
    //     else
    //             printf("No error\n");
    // return 0;
}