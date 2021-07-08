#include "pipex.h"

int ft_strlen(char *str)
{
    int ret;

    ret = 0;
    while (str[ret])
        ret++;
    return (ret);
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

