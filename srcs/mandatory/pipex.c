/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:15:13 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/15 22:06:26 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	forking(t_pipe *cmd)
{
	int nb_fork1;
	int nb_fork2;

	nb_fork1 = fork();
	if (nb_fork1 < 0)
	{
		free_cmd(cmd);
		exit(EXIT_FAILURE);
	}
	if (nb_fork1 == 0)
		exec_cmd1(cmd);
	close(cmd->fd[1]);
	nb_fork2 = fork();
	if (nb_fork2 < 0)
	{
		free_cmd(cmd);
		exit(EXIT_FAILURE);
	}
	if (nb_fork2 == 0)
		exec_cmd2(cmd);
	close(cmd->fd[0]);
	waitpid(nb_fork1, NULL, 0);
	waitpid(nb_fork2, NULL, 0);
}

bool	open_and_pipe(char **argv, t_pipe *cmd)
{
	cmd->infile = open(argv[1], O_RDONLY, 0444);
	if (cmd->infile == -1)
		return (perror(argv[1]), false);
	cmd->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (cmd->outfile == -1)
		return (perror(argv[4]), false);
	pipe(cmd->fd);
	return (true);
}

t_pipe	*commands_in_cmd(char **argv)
{
	t_pipe	*cmd;

	cmd = malloc(sizeof(t_pipe));
	cmd->cmd1 = ft_split(argv[2], ' ');
	cmd->cmd2 = ft_split(argv[3], ' ');
	if (cmd->cmd1[0] == NULL)
	{
		ft_putstr_fd("permission denied: \n", STDERR_FILENO);
		free_cmd(cmd);
		return (cmd = NULL, NULL);
	}
	if (cmd->cmd2[0] == NULL)
	{
		ft_putstr_fd("permission denied: \n", STDERR_FILENO);
		free_cmd(cmd);
		return (cmd = NULL, NULL);
	}
	cmd->infile = -1;
	cmd->outfile = -1;
	cmd->fd[0] = -1;
	cmd->fd[1] = -1;
	return (cmd);
}

t_pipe	*parsing(char **argv, char **envp)
{
	t_pipe	*cmd;

	cmd = commands_in_cmd(argv);
	if (cmd == NULL)
		return (NULL);
	cmd->cmd1[0] = get_path_command(cmd->cmd1[0], envp);
	cmd->cmd2[0] = get_path_command(cmd->cmd2[0], envp);
	if (cmd->cmd1[0] == NULL || cmd->cmd2[0] == NULL)
	{
		free_cmd(cmd);
		return (cmd = NULL, NULL);
	}
	if (open_and_pipe(argv, cmd) == false)
	{
		free_cmd(cmd);
		cmd = NULL;
	}
	return (cmd);
}

int main(int argc, char **argv, char **envp)
{
	t_pipe	*cmd;

	if (argc < 2 || argc > 5)
	{
		ft_printf_fd(2, "Too much command or arguments");
		return (1);
	}
	cmd = parsing(argv, envp);
	if (cmd == NULL)
		exit(EXIT_FAILURE);
	forking(cmd);
	free_cmd(cmd);
}