#include "ft_pipex.h"

void	create_child(int *pid)
{
	*pid = fork();
	if (*pid == -1)
		perror("\n\n\t\tPid error\n\n");
}

int	ft_strlen(char *str)
{
	int	ret;

	ret = 0;
	while (str[ret])
		ret++;
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		sizetotal;

	if (!s1 || !s2)
		return (NULL);
	sizetotal = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = (char *)malloc(sizetotal + 1);
	if (!str)
		return (NULL);
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (str - sizetotal);
}

char	*ft_str3join(char *s1, char *s2, char *s3)
{
	char	*str;
	int		sizetotal;

	if (!s1 || !s2 || !s3)
		return (NULL);
	sizetotal = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	str = (char *)malloc(sizetotal + 1);
	if (!str)
		return (NULL);
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	while (*s3)
		*str++ = *s3++;
	*str = '\0';
	return (str - sizetotal);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		size;

	size = ft_strlen((char *)s1);
	dup = (char *)malloc(size + 1);
	if (!dup)
		return (NULL);
	while (*s1)
	{
		*dup = *(char *)s1;
		s1++;
		dup++;
	}
	*dup = '\0';
	
	return (dup - size);
}