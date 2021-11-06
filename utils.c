#include "ft_pipex.h"

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

int	count_words(char *str)
{
	int	ret;

	ret = 0;
	while (*str)
	{
		if ((*str == ' ' && *(str + 1) != '\0'))
			ret++;
		str++;
	}
	return (ret);
}

static int	size_spaces(char *str, char c)
{
	int	i;
	int	j;
	int	spaces;

	i = 0;
	j = ft_strlen(str);
	spaces = 0;
	while (str[i] == c || str[j - 1] == c)
	{
		if (str[i] == c)
			spaces++;
		if (str[j - 1] == c)
			spaces++;
		i++;
		j--;
	}
	return (spaces);
}

char	*str_trim(char *str, char c)
{
	int		i;
	int		j;
	int		spaces;
	char	*ret;

	i = 0;
	j = 0;
	spaces = size_spaces(str, c);
	if (spaces == 0)
	{
		ret = malloc(sizeof(str) + 1);
		ret = str;
		return (ret);
	}
	ret = malloc(sizeof(str) - spaces + 1);
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
			ret[j++] = str[i++];
	}
	ret[j] = '\0';
	return (str);
}

char	*ft_strndup(const char *s1, int len)
{
	char	*dup;
	int		i;

	if (ft_strlen((char *)s1) <= len)
		return (ft_strdup(s1));
	dup = (char *)malloc(ft_strlen((char *)s1) + 1);
	if (!dup)
		return (NULL);
	i = -1;
	while (++i < len)
		dup[i] = s1[i];
	dup[i] = '\0';
	return (dup);
}
