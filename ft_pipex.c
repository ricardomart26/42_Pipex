#include "ft_pipex.h"

void	store_output_exec(t_info *st, char **av, int i)
{
	int	fd;

	st->cmd = split(av[i], ' ');
	close(st->pipefd[0]);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		perror("First Fd not found\n");
	close(fd);
	dup2(st->pipefd[1], STDOUT_FILENO);
	close(st->pipefd[1]);
	ft_execve_cmd(st);
}

void	send_file(t_info *st, char **av, int i)
{
	int	fd;

	st->cmd = split(av[i], ' ');
	close(st->pipefd[1]);
	fd = open(av[4], O_CREAT | O_TRUNC | O_WRONLY);
	if (fd < 0)
		perror("First Fd not found\n");
	dup2(st->pipefd[0], STDIN_FILENO);
	close(st->pipefd[0]);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	ft_execve_cmd(st);
}

void	ft_execve_cmd(t_info *st)
{
	char	**dir;
	char	*path;
	int		x;
	int i = 0;

	x = 0;
	dir = split(st->path, ':');
	while (dir[x])
	{
		if (st->cmd[0][0] != '/')
			path = ft_str3join(dir[x], "/", st->cmd[0]);
		else
			path = *st->cmd;
		execve(path, st->cmd, NULL);
		free(path);
		x++;
	}
	while (dir[i])
		free(dir[i++]);
	free(dir);
}

t_info	handle_processes(t_info st, char **av)
{
	int	i;

	if (pipe(st.pipefd) == -1)
		perror("\n\n\t\tPipe error\n\n");
	create_child(&st.pid);
	if (st.pid == 0)
		store_output_exec(&st, av, 2);
	else
		wait(NULL);
	send_file(&st, av, 3);
	i = 0;
	while (st.cmd[i])
		free(st.cmd[i++]);
	free(st.cmd);
	st.cmd = NULL;
	return (st);
}

int	main(int ac, char **av, char **env)
{
	t_info	st;

	if (ac < 5)
		perror("\n\n\t\tMissing comands\n\n");
	st.path = get_env_path(env);
	st.ac = ac;
	st = handle_processes(st, av);
	return (0);
}
