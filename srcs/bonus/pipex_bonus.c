/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:30:01 by syluiset          #+#    #+#             */
/*   Updated: 2023/04/12 20:26:32 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	forking_bonus(t_pipe *pipex)
{
	int	execution;

	execution = 0;
	while (execution < pipex->nb_exec)
	{
		if (execution != pipex->nb_exec - 1)
			exec_pipex(pipex, pipex->cmd[execution], 0, execution);
		else
		{
			pipex->outfile = open(pipex->outfile_path,
								  O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (pipex->outfile < 0)
				pipex->should_last = false;
			exec_pipex(pipex, pipex->cmd[execution], 1, execution);
		}
		execution++;
	}
	while (execution--)
		wait(NULL);
}

char	***get_all_command(char **argv, bool is_hd, int nb_ex)
{
	char	***tab;
	int		i;
	int		count;

	count = 0;
	if (is_hd == false)
		i = 2;
	else
		i = 3;
	tab = malloc(sizeof(char **) * (nb_ex + 1));
	if (!tab)
		return (NULL);
	while (count < nb_ex)
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
	tab[count] = NULL;
	return (tab);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	*pipex;
	bool	is_hd;
	bool	should_first;

	is_hd = false;
	if (argc < 5)
	{
		ft_printf_fd(2, "Too much or not enough arguments");
		return (1);
	}
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1]) + 1) == 0)
		is_hd = true;
	else
		should_first = open_and_pipe_bonus(argv);
	pipex = parsing_bonus(argc, argv, envp, is_hd);
	pipex->should_frst = should_first;
	if (is_hd == true)
		here_doc(pipex);
	forking_bonus(pipex);
	free_pipe(pipex);
}
