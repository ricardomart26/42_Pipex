#include "pipex.h"

void	ft_execve(t_info *st)
{
	char	**dir;
	char	*path;
	int		x;

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
}

void            get_and_store_exec(t_info *st, int fd, char **av)
{
    st->cmd = split(av[st->i], ' ');
    dup2(fd, STDIN_FILENO);
    close (fd);
    close(st->pipefd[0]);
    dup2(st->pipefd[1], STDOUT_FILENO);
    close(st->pipefd[1]);
    ft_execve(st);
}

void            store_output_exec(t_info *st, char **av)
{
	int	fd;


	st->cmd = split(av[st->i], ' ');
	close(st->pipefd[0]);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		perror("First Fd not found\n");
	close(fd);
    
	dup2(st->pipefd[1], STDOUT_FILENO);
	close(st->pipefd[1]);
	ft_execve(st);
}

void send_file(t_info *st, char **av, int temp)
{
    int fd;
	st->cmd = split(av[st->i], ' ');
	close(st->pipefd[1]);
	fd = open(av[st->i + 1], O_CREAT | O_TRUNC | O_WRONLY);
	if (fd < 0)
		perror("First Fd not found\n");
	dup2(temp, STDIN_FILENO);
	close(temp);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	ft_execve(st);
}

t_info handle_processes(t_info st, char **av)
{
    int fd;
    
    while (st.cmd_counter != -1)
    {
        if (pipe(st.pipefd) == -1) // Criar o pipe que retorna um array de 2 ints, p[0] e p[1] do pipe
            perror("\n\n\t\tPipe error\n\n");
        st.i++;
        if (st.cmd_counter != 0) // Criamos o child process ate ao ultimo comando
            create_child(&st.pid);
        if (st.pid == 0 && st.cmd_counter != 0)
        {
            printf("st->counter = %d\n", st.cmd_counter);
            if (st.cmd_counter == st.ac - 4)
                store_output_exec(&st, av);
            else
                get_and_store_exec(&st, fd, av);
        }
        else
        {
            waitpid(st.pid,NULL,1);
            fd = st.pipefd[0];
            close(st.pipefd[0]);
            close(st.pipefd[1]);
            if (st.cmd_counter == 0)
                send_file(&st, av, fd);

            st.cmd_counter--;
        }
    }
    return (st);
}


int main(int ac, char **av, char **envp)
{
    t_info st;

    if (ac < 5)
    {
        perror("\n\n\t\tMissing comands\n\n");
        exit(0);
    }
    
    /* 
        Função para recever o path das environment variables
        Este path vai ser usado no execve porque tem todas as 
        caminhos para os comandos.
    */
    st.path = get_env_path(envp); 
    st.ac = ac; 
    st.i = 1;
    st.cmd_counter = ac - 4; // Numero de comandos

    // printf("\n\n\t\tThe path is: %s\n\n", st.path);
    
    
    
    st = handle_processes(st, av); // main funct

    return (0);
}