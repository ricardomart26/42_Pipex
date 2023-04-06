#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_info
{
	pid_t	pid;
	char	**cmd;
	int		pipefd[2];
	char	*path;
	int		ac;
	int		stdin_file;
	int		stdout_file;
}	t_info;

char	*ft_str3join(char *s1, char *s2, char *s3);
int		ft_strcmp(char *path, char *env, size_t size);
char	*get_env_path(char **envp);
char	**split(char const *s, char c);
void	ft_execve_cmd(t_info *st, char **env);
int		ft_strlen(const char *str);
int		error_message(char *msg);

#endif