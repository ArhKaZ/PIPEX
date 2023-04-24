/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:15:13 by syluiset          #+#    #+#             */
/*   Updated: 2023/04/24 17:16:56 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	forking(t_pipe *cmd)
{
	int	nb_fork1;
	int	nb_fork2;

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
	bool	ret;

	ret = true;
	cmd->infile = open(argv[1], O_RDONLY, 0644);
	if (cmd->infile == -1)
	{
		perror(argv[1]);
		ret = false;
	}
	cmd->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (cmd->outfile == -1)
	{
		perror(argv[4]);
		ret = false;
	}
	pipe(cmd->fd);
	return (ret);
}

t_pipe	*commands_in_cmd(char **argv)
{
	t_pipe	*cmd;

	cmd = malloc(sizeof(t_pipe));
	cmd->cmd1 = ft_split(argv[2], ' ');
	cmd->cmd2 = ft_split(argv[3], ' ');
	if (cmd->cmd1[0] == NULL)
		ft_putstr_fd("permission denied: \n", STDERR_FILENO);
	if (cmd->cmd2[0] == NULL)
		ft_putstr_fd("permission denied: \n", STDERR_FILENO);
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
	open_and_pipe(argv, cmd);
	cmd->cmd1[0] = get_path_command(cmd->cmd1[0], envp);
	cmd->cmd2[0] = get_path_command(cmd->cmd2[0], envp);
	return (cmd);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	*cmd;

	if (argc != 5)
	{
		ft_printf_fd(2, "Too much or not enough arguments");
		return (1);
	}
	cmd = parsing(argv, envp);
	if (cmd == NULL)
		exit(EXIT_FAILURE);
	forking(cmd);
	free_cmd(cmd);
}
