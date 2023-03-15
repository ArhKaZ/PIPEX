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

void	forking(t_cmd *cmd)
{
	int nb_fork1;
	int nb_fork2;
	int status1;
	int status2;

	nb_fork1 = fork();
	nb_fork2 = fork();
	if (nb_fork1 == 0) {
		exec_cmd1(cmd);
	}
	else
		wait(&status1);
	if (nb_fork2 == 0) {
		exec_cmd2(cmd);
	}
	else
		wait(&status2);

}

t_cmd	*parsing(char **argv, char **envp)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	cmd->cmd1 = ft_split(argv[2], ' ');
	cmd->cmd2 = ft_split(argv[3], ' ');
	if (cmd->cmd1[0] == NULL || cmd->cmd2[0] == NULL)
		return (NULL);
	cmd->cmd1[0] = get_path_command(cmd->cmd1[0], envp);
	cmd->cmd2[0] = get_path_command(cmd->cmd2[0], envp);
	cmd->infile = ft_strdup(argv[1]);
	cmd->outfile = ft_strdup(argv[4]);
	if (cmd->cmd1[0] == NULL || cmd->cmd2[0] == NULL
		|| cmd->infile == NULL || cmd->outfile == NULL)
		return (NULL);
	pipe(cmd->fd);
	return (cmd);
}

int main(int argc, char **argv, char **envp)
{
	t_cmd	*cmd;

	if (argc < 2 || argc > 5)
		return (1);
	cmd = parsing(argv, envp);
	forking(cmd);
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