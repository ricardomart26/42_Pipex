#include "pipex.h"

void create_child(int *pid)
{
    *pid = fork();
    if (*pid == -1)
        perror("\n\n\t\tPid error\n\n");
}

int ft_letter(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
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