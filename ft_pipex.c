#include "ft_pipex.h"

char	*get_env_path(char **envp)
{
	int	x;

	x = 0;
	while (envp[x])
	{
		if (ft_strcmp("PATH", envp[x], 4))
			return (envp[x] + 5);
		x++;
	}
	return (NULL);
}

void	ft_execve_cmd(t_info *st, char **env)
{
	char	**dir;
	char	*path;
	int		x;
	int		i;

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
			st.stdout_file = st.pipefd[1];
			if (j == command_count - 1)
			{
				st.stdout_file = open(av[j + 1], O_CREAT | O_TRUNC | O_WRONLY);
				if (st.stdout_file == -1)
					return (error_message("stdout file error\n"));
			}
			st.cmd = split(av[j], ' ');
			dup2(st.stdin_file, STDIN_FILENO);
			dup2(st.stdout_file, STDOUT_FILENO);
			ft_execve_cmd(&st, env);
		}
		close(st.stdin_file);
		st.stdin_file = dup(st.pipefd[0]);
		close(st.pipefd[0]);
		close(st.pipefd[1]);
	}
	return (1);
}

int	main(int ac, char **av, char **env)
{
	t_info	st;
	size_t	j;

	if (ac < 5)
		return (error_message("Usage: ./pipex file_for_stdin cmd1 cmd2 file_for_stdout\n"));
	st.path = get_env_path(env);
	st.ac = ac;
	st.stdin_file = open(av[1], O_RDONLY);
	if (st.stdin_file == -1)
		return (error_message("stdin file error\n"));
	if (handle_processes(st, av, env, ac - 1) == -1)
		return (-1);
	j = 1;
	while (++j < (size_t)ac - 1)
		wait(NULL);
	return (0);
}
