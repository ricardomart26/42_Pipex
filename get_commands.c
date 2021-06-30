#include "ft_pipex.h"

void    get_command(t_info *st, char **av, int i)
{
    int x;
    int flags;

    x = 0;
    printf("\tGETTING COMMAND...\n");
    printf("\n\tav = %s", av[i]);
    flags = count_words(av[i]);
    if (flags == 0)
    {
        // printf("\nNO FLAGS\n");
        st->cmd[x++] = str_trim(av[i], ' ');
        st->cmd[x] = NULL;
    }
    else
        st->cmd = split(av[i], ' ');
}


char *get_env_path(char **envp)
{
    int x;

    x = 0;

    /* 
        Loop para avançar nas variaveis do sistema (env no terminal para ver)
        até chegar ao PATH onde estas os caminhos dos comandos
    */
    while (envp[x])
    {
        if (ft_strcmp("PATH", envp[x], 4))
            return (envp[x] + 5); // Nao queremos a parte que diz path, por isso avançamos 5 pos
        x++;
    }
    return (NULL);
}

