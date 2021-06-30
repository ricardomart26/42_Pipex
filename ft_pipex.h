#ifndef FT_PIPEX_H
#define FT_PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>


typedef struct s_info
{
    pid_t pid;
    char **cmd;

    int pipefd[2];
    char *env; 
    char *path; 
    int ac;
} t_info;

char	*ft_str3join(char const *s1, char const *s2, char const *s3);
char	*ft_strjoin(char const *s1, char const *s2);    
void            store_output_exec(t_info *st, char **av);
void create_child(int *pid);

int ft_strcmp(char *path, char *env, size_t size);
void    get_command(t_info *st, char **av, int i);
char *get_env_path(char **envp);
int count_words(char *str);
char		**split(char const *s, char c);
void ft_execve_cmd(t_info *st);
char *str_trim(char *str, char c);






#endif