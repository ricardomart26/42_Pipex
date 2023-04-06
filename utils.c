#include "ft_pipex.h"

int error_message(char *msg)
{
	perror(msg);
	return (-1);
}

int	ft_strlen(const char *str)
{
	int	ret;

	ret = 0;
	while (str[ret])
		ret++;
	return (ret);
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

int	ft_strcmp(char *path, char *env, size_t size)
{
	size_t	c;

	c = 0;
	while (path[c] != '\0' && c != size)
	{
		if (path[c] != env[c])
			return (0);
		c++;
	}
	return (1);
}
