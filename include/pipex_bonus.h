/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:34:39 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/27 11:25:28 by syluiset         ###   ########.fr       */
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
# include <errno.h>
# include <string.h>
# include "../Libft_w_a/libft.h"

typedef struct s_pipe
{
	char 	***cmd;
	int 	fd[2];
	int 	infile;
	char	*outfile_path;
	int 	outfile;
	char 	*limiter;
	int 	nb_exec;
	bool	is_hd;
}				t_pipe;

void	free_pipe(t_pipe *pipe);

char	*get_path_command(char *command, char **envp);

void	free_three_char_tab(char ***tab);

void	exec_first_cmd(t_pipe *cmd);

void	exec_cmd_n(t_pipe *cmd, int nb);

void	exec_last_cmd(t_pipe *cmd, int nb);

void	free_char_tab(char **tab);

void	here_doc(char *limiter);

void	launch_here_doc(t_pipe *pipex);

void	here_doc_exec(t_pipe *pipex);
#endif