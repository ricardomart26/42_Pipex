#include "ft_pipex.h"

int ft_strlen(char *str)
{
    int ret;

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


char	*ft_str3join(char const *s1, char const *s2, char const *s3)
{
	char	*str;
	int		sizetotal;

	if (!s1 || !s2 || !s3)
		return (NULL);
	sizetotal = ft_strlen((char *)s1) + ft_strlen((char *)s2) + ft_strlen((char *)s3);
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

int ft_strcmp(char *path, char *env, size_t size)
{
    size_t c;

    c = 0;
    // printf("env = %s\n", env);
    while (path[c] != '\0' && c != size)
    {
        if (path[c] != env[c])
            return (0);
        c++;
    }
    return (1);
}

int count_words(char *str)
{
    int ret;
    ret = 0;
    while (*str)
    {
        if ((*str == ' ' && *(str + 1) == '-'))
            ret++;
        str++; 
    }
    return (ret);
}

static int size_spaces(char *str, char c)
{
    int i;
    int j;
    int spaces;

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

char *str_trim(char *str, char c)
{
    int i;
    int j;
    int spaces;
    char *ret;

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