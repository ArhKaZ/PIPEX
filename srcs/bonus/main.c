#include "../../include/pipex_bonus.h

void	ft_pipex(char **cmd, char **env, int last) {
	int		fd[2];
	pid_t	pid;

	pipe(&fd[0]);
	pid = fork();

	//	if (pid < 0) {
			//error
	//	}
	if (pid > 0) {
		//parent

		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);

		waitpid(0, NULL, -1);
	}
	if (pid == 0) {
		//child

		close(fd[0]);
		if (!last)
			dup2(fd[1], STDIN_FILENO);
		close(fd[1]);

		execve(cmd[0], cmd, env);
	}
}

void	appel_pipex(s_pipe *structure) {
	if (!structure->is_hd) {
		dup2(structure->infile, STDIN_FILENO);
		close(struture->infile);
	}
	int	i = 0;
	while (structure->cmd[i]) {
		if (i != structure->nb_exec - 1)
			ft_pipex(structure->cmd[i], env, 0);
		else (i != structure->nb_exec - 1) {
			open(structure->fd_out);
			ft_pipex(structure->cmd[i], env, 1);
		}
	}
}


HD
0 IN
1 OUT
2 ERROR

INFILE
0 INFILE
1 OUT
2 ERROR