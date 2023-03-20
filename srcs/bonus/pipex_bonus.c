/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:30:01 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/20 13:30:01 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	forking_bonus(t_pipe *pipe)
{
	int nb_exec;

	nb_exec = 1;
	pipe->fork_int = malloc(sizeof(int) * pipe->nb_exec);
	pipe->fork_int[0] = fork();
	if (pipe->fork_int[0] == 0)
		exec_first_cmd(pipe);
	close(pipe->fd[0][1]);
	while (nb_exec < pipe->nb_exec - 1)
	{
		pipe->fork_int[nb_exec] = fork();
		if (pipe->fork_int[nb_exec] == 0)
			exec_cmd_n(pipe, nb_exec);
		nb_exec++;
	}
	pipe->fork_int[nb_exec] = fork();
	if (pipe->fork_int[nb_exec] == 0)
		exec_last_cmd(pipe);
	while (nb_exec > 0)
	{
		waitpid(pipe->fork_int[nb_exec], NULL, 0);
		nb_exec--;
	}
}

char	***get_all_command(int argc, char **argv)
{
	char 	***tab;
	int		i;
	int 	count;

	count = 0;
	i = 2;
	tab = malloc(sizeof(char **) * argc - 3);
	while (argv[i + 1] != NULL)
	{
		tab[count] = ft_split(argv[i], ' ');
		if (tab[count] == NULL)
		{
			free_three_char_tab(tab);
			return (ft_printf_fd(STDERR_FILENO, "command not found :"), NULL);
		}
		i++;
		count++;
	}
	return (tab);
}

bool	open_bonus(int argc, char **argv, t_pipe *cmd)
{
	int	nb_exec;

	nb_exec = 0;
	cmd->infile = open(argv[1], O_RDONLY, 0444);
	if (cmd->infile == -1)
		return (perror(argv[1]), false);
	cmd->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (cmd->outfile == -1)
		return (perror(argv[argc - 1]), false);
	cmd->fd = malloc(sizeof(int *) * cmd->nb_exec - 1);
	while (nb_exec < cmd->nb_exec - 1)
	{
		cmd->fd[nb_exec] = malloc(sizeof(int) * 2);
		pipe(cmd->fd[nb_exec]);
		ft_printf("%d/%d\n", cmd->fd[nb_exec][0], cmd->fd[nb_exec][1]);
		nb_exec++;
	}
	return (true);
}

t_pipe	*parsing_bonus(int argc, char **argv, char **envp)
{
	t_pipe	*pipe;
	int		i;

	i = 0;
	pipe = malloc(sizeof(t_pipe));
	pipe->cmd = get_all_command(argc, argv);
	while (pipe->cmd[i])
	{
		pipe->cmd[i][0] = get_path_command(pipe->cmd[i][0], envp);
		if (pipe->cmd[i][0] == NULL)
			return (free_pipe(pipe), pipe = NULL, NULL);
		i++;
	}
	pipe->nb_exec = argc - 3;
	if (open_bonus(argc, argv, pipe) == false)
	{
		free_pipe(pipe);
		pipe = NULL;
	}
	return (pipe);
}

int main(int argc, char **argv, char **envp)
{
	t_pipe *pipe;

	if (argc < 5)
		return (1);
	pipe = parsing_bonus(argc, argv, envp);
	if (pipe == NULL)
		exit(EXIT_FAILURE);
	forking_bonus(pipe);
	free_pipe(pipe);
}