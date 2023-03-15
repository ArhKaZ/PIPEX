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
# include "../Libft_w_a/libft.h"

typedef struct s_argu
{
	int		fd_pipe[2];
	int		fd_files[2];
}				t_argu;

typedef struct s_cmd
{
	char	*path;
	char	*arg1;
	char	*arg2;
	char	*arg3;
}				t_cmd;

void	free_char_tab(char **tab);

char	*get_path_command(char *command, char **envp);
#endif