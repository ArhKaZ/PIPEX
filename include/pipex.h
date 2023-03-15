/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:15:42 by syluiset          #+#    #+#             */
/*   Updated: 2023/03/14 16:24:05 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <stdbool.h>
# include <wait.h>
# include "../Libft_w_a/libft.h"

typedef struct s_cmd
{
	char 	**cmd1;
	char 	**cmd2;
	int 	fd[2];
	char 	*infile;
	char 	*outfile;
}				t_cmd;

void	free_char_tab(char **tab);

char	*get_path_command(char *command, char **envp);

void	exec_cmd1(t_cmd *cmd);

void	exec_cmd2(t_cmd *cmd);

#endif