#ifndef _PIPEX_H_
#define _PIPEX_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <fcntl.h>

typedef struct info_s
{
    char **cmd;
    int cmd_counter;
    pid_t pid;
    int pipefd0[2];
    int pipefd[2];
    char *env;
    char *path;
    int i;
    int ac;
}   t_info;

int ft_strcmp(char *path, char *env, size_t size);
char *str_trim(char *str, char c);
int ft_strlen(char *str);
char **malloc_dp(char *str, char c, int option);
char **split(char const *str, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_str3join(char const *s1, char const *s2, char const *s3);
char *get_env_path(char **envp);
// void    get_command(t_info *st, char **av, int i);

void create_child(int *pid);
int count_words(char *str);

#endif