/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:25:08 by syluiset          #+#    #+#             */
/*   Updated: 2023/04/12 20:31:57 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

bool	open_and_pipe_bonus(char **argv)
{
	int infile;

	infile = 0;
	infile = open(argv[1], O_RDONLY, 0444);
	if (infile < 0)
		return (perror(argv[1]), false);
	dup2(infile, STDIN_FILENO);
	close(infile);
	return (true);
}

char	**cp_tab(char **to_cp)
{
	int		i;
	char	**cp;

	i = 0;
	while (to_cp[i])
		i++;
	cp = malloc(sizeof(char *) * (i + 1));
	if (!cp)
		return (NULL);
	i = 0;
	while (to_cp[i])
	{
		cp[i] = ft_strdup(to_cp[i]);
		i++;
	}
	cp[i] = NULL;
	return (cp);
}

void	is_it_hd(t_pipe **pipe, bool is_hd, char *limite, int argc)
{
	if (is_hd == false)
	{
		(*pipe)->limiter = NULL;
		(*pipe)->nb_exec = argc - 3;
	}
	else
	{
		(*pipe)->limiter = ft_strjoin(limite, "\n");
		if ((*pipe)->limiter == NULL)
			free_pipe(*pipe);
		(*pipe)->nb_exec = argc - 4;
	}
}

t_pipe	*parsing_bonus(int argc, char **argv, char **envp, bool is_hd)
{
	t_pipe	*pipe;
	int		i;

	i = 0;
	pipe = malloc(sizeof(t_pipe));
	if (!pipe)
		return (NULL);
	pipe->should_last = true;
	pipe->should_frst = true;
	pipe->is_hd = is_hd;
	pipe->envp = cp_tab(envp);
	if (pipe->envp == NULL)
		return (free(pipe), NULL);
	is_it_hd(&pipe, is_hd, argv[2], argc);
	pipe->cmd = get_all_command(argv, is_hd, pipe->nb_exec);
	if (pipe->cmd == NULL)
		return (free(pipe), NULL);
	while (i < pipe->nb_exec)
	{
		pipe->cmd[i][0] = get_path_command(pipe->cmd[i][0], pipe->envp);
		if (pipe->cmd[i][0] == NULL)
			return (free(pipe), pipe = NULL, NULL);
		i++;
	}
	pipe->outfile_path = ft_strdup(argv[argc - 1]);
	if (pipe->outfile_path == NULL)
		return (free(pipe), NULL);
	return (pipe);
}
