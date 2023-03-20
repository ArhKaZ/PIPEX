/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:34:39 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/20 13:34:39 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <stdbool.h>
# include <wait.h>
# include <string.h>
# include "../Libft_w_a/libft.h"

typedef struct s_pipe
{
	char 	***cmd;
	int 	**fd;
	int 	*fork_int;
	int 	infile;
	int 	outfile;
	int 	nb_exec;
}				t_pipe;

void	free_pipe(t_pipe *pipe);

char	*get_path_command(char *command, char **envp);

void	free_three_char_tab(char ***tab);

void	exec_first_cmd(t_pipe *cmd);

void	exec_cmd_n(t_pipe *cmd, int nb);

void	exec_last_cmd(t_pipe *cmd);

void	free_char_tab(char **tab);

void	close_fd(t_pipe *pipe);
#endif