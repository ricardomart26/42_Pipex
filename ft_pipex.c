#include "ft_pipex.h"

void            store_output_exec(t_info *st, char **av)
{
    int fd;
    
    close(st->pipefd[0]); // Fechamos o write do pipe
    fd = open(av[1], O_RDONLY); // Abrir ficheiro para verificar se esta aberto
    if (fd < 0)
        printf("\n\tfile doestn exist!\n");
    printf("\n\tGOOD FILE\n");
    close(fd); // Fechamos o ficheiro
    dup2(st->pipefd[1], STDOUT_FILENO); // Escrevemos o STOUT do comando para o pipe
    close(st->pipefd[1]); // Fechamos o ewad do pipe
    ft_execve_cmd(st); // Executamos o comando
}


// else if (pid == 0) { //Child
//     dup2(pd[0], 0); // O read fica o stdin do child e do comando
//     close(pd[0]); // Fechamos o  read do pipe
//     close(pd[1]); // Fechamos o write do pipe
//     execlp("wc", "wc", "-l", (char *)NULL); // Vai mandar o comando para o stdin
//     fprintf(stderr, "Failed to execute 'wc'\n");
//     exit(1);
// }

void send_file(t_info *st, char **av)
{
    int fd;

    close(st->pipefd[1]);
    printf("\n\tPrint av[4] = %s!\n", av[4]);
    
    fd = open(av[4], O_CREAT | O_TRUNC | O_WRONLY);
    
    dup2(st->pipefd[0], STDIN_FILENO);
    close(st->pipefd[0]);
    dup2(fd, STDOUT_FILENO);
    close(fd);

    ft_execve_cmd(st);
}



void ft_execve_cmd(t_info *st)
{
    char **dir;
    char *path;
    int x;

    x = 0;

    dir =  split(st->path, ':');
    printf("\tdir = %s...\n", dir[x]);
    while (dir[x])
    {
        // printf("\nCHEGOU AQUI EXECVE!\n");
        if (st->cmd[0][0] != '/')
            path = ft_str3join(dir[x], "/" , st->cmd[0]);
        else
            path = *st->cmd;
        printf("\n\tTHIS IS THE PATH OF THE COMMAND %s\n", path);
        execve(path, st->cmd, NULL);
        x++;
    }
}


t_info handle_processes(t_info st, char **av)
{
    /* 
        Enquanto houver comandos vamos criar child processes para 
        podermos executar o comando e escrever no p[1] do pipe o input
        do comando
    */ 
    if (pipe(st.pipefd) == -1) // Criar o pipe que retorna um array de 2 ints, p[0] e p[1] do pipe
        perror("\n\n\t\tPipe error\n\n");
    // st.i++;
    // if (st.cmd_counter != 0) // Criamos o child process ate ao ultimo comando
    create_child(&st.pid); 
    if (st.pid == 0)
    {
        printf("\n\tCHILD ALIVE BITCH!!\n\n");
        get_command(&st, av, 2);
        store_output_exec(&st, av);
    }
    else
    {
        wait(NULL);
        printf("\n\tChild Process died YEY\n");
        get_command(&st, av, 3);
        send_file(&st, av);
    }
    return (st);
}



int main(int ac, char **av, char **env)
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
    st.path = get_env_path(env); 
    st.ac = ac; 

    // printf("\n\n\t\tThe path is: %s\n\n", st.path);
    
    
    
    st = handle_processes(st, av); // main funct

    return (0);

    
}