/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:30:01 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/27 11:59:58 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	forking_bonus(t_pipe *pipe)
{
	int nb_exec;
	int side_pipe;

	side_pipe = 1;
	nb_exec = 0;
	pipe->fork_int = malloc(sizeof(int) * pipe->nb_exec);
	while (nb_exec < pipe->nb_exec)
	{
		pipe->fork_int[nb_exec] = fork();
		if (pipe->fork_int[nb_exec] == 0)
		{
			if (nb_exec == 0)
				exec_first_cmd(pipe);
			else if (nb_exec == pipe->nb_exec - 1)
				exec_last_cmd(pipe, nb_exec);
			else
				exec_cmd_n(pipe, nb_exec);
			if (nb_exec < pipe->nb_exec - 1)
				close(pipe->fd[nb_exec][side_pipe]);
			if (side_pipe == 1)
				side_pipe = 0;
			else
				side_pipe = 1;
		}
		else
			waitpid(pipe->fork_int[nb_exec], NULL, 0);
		nb_exec++;
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
		if (tab[count][0] == NULL)
		{
			free_three_char_tab(tab);
			return (ft_printf_fd(STDERR_FILENO, "permission denied:"), NULL);
		}
		i++;
		count++;
	}
	return (tab);
}

bool	open_and_pipe_bonus(int argc, char **argv, t_pipe *cmd)
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
	if (pipe->cmd == NULL)
		return (free(pipe), NULL);
	while (pipe->cmd[i])
	{
		pipe->cmd[i][0] = get_path_command(pipe->cmd[i][0], envp);
		if (pipe->cmd[i][0] == NULL)
			return (free_pipe(pipe), pipe = NULL, NULL);
		i++;
	}
	pipe->nb_exec = argc - 3;
	if (open_and_pipe_bonus(argc, argv, pipe) == false)
	{
		free_pipe(pipe);
		pipe = NULL;
	}
	return (pipe);
}

int main(int argc, char **argv, char **envp)
{
	t_pipe *pipe;
	char	*limiter;
	if (argc < 5)
		return (1);
	if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")))
		limiter = ft_strdup(argv[2]);
	pipe = parsing_bonus(argc, argv, envp);
	if (pipe == NULL)
		exit(EXIT_FAILURE);
	forking_bonus(pipe);
	free_pipe(pipe);
}