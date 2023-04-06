#include "ft_pipex.h"

int error_message(char *msg)
{
	perror(msg);
	return (-1);
}

void	ft_execve_cmd(t_info *st, char **env, int stdin_file, int stdout_file)
{
	char	**dir;
	char	*path;
	int		x;
	int		i;

	dup2(stdin_file, STDIN_FILENO);
	dup2(stdout_file, STDOUT_FILENO);
	x = 0;
	dir = split(st->path, ':');
	while (dir[x])
	{
		if (st->cmd[0][0] != '/')
			path = ft_str3join(dir[x], "/", st->cmd[0]);
		else
			path = *st->cmd;
		execve(path, st->cmd, env);
		free(path);
		x++;
	}
	i = 0;
	while (dir[i])
		free(dir[i++]);
	free(dir);
}

int	handle_processes(t_info st, char **av, char **env, size_t command_count)
{
	size_t	j;
	int stdin_file;
	int stdout_file;
	
	stdin_file = open(av[1], O_RDONLY);
	if (stdin_file == -1)
		return (error_message("stdin file error\n"));
	j = 1;
    while (++j < command_count)
	{

		if (pipe(st.pipefd) == -1)
			return (error_message("Pipe error\n"));
		st.pid = fork();
		if (st.pid == -1)
			return (error_message("Pid error\n"));
		if (st.pid == 0)
		{

			stdout_file = st.pipefd[1];
			if (j == command_count - 1)
			{
				stdout_file = open(av[j + 1], O_CREAT | O_TRUNC | O_WRONLY);
				if (stdout_file == -1)
					return (error_message("stdout file error\n"));
			}
			// fprintf(stderr, "stdin %d stdout %d\n", stdin_file, stdout_file);
			st.cmd = split(av[j], ' ');
			ft_execve_cmd(&st, env, stdin_file, stdout_file);
		}
		close(stdin_file);
		stdin_file = dup(st.pipefd[0]);
		close(st.pipefd[0]);
		close(st.pipefd[1]);
	}
	j = 1;
	while (++j < command_count)
		wait(NULL);
	return (1);
}

int	main(int ac, char **av, char **env)
{
	t_info	st;

	if (ac < 5)
		return (error_message("Usage: ./pipex file_for_stdin cmd1 cmd2 file_for_stdout\n"));
	st.path = get_env_path(env);
	st.ac = ac;
	if (handle_processes(st, av, env, ac - 1) == -1)
		return (-1);
	return (0);
}
