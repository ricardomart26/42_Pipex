#include "ft_pipex.h"

char	*get_env_path(char **envp)
{
	int	x;

	x = 0;
	while (envp[x])
	{
		if (ft_strcmp("PATH", envp[x], 4))
			return (envp[x] + 5);
		x++;
	}
	return (NULL);
}

static int	ft_cntwrd(char const *s, char c)
{
	unsigned int	i;
	int				counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			counter++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (counter);
}

char	**split(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_cntwrd(s, c) + 1));
	if (!tab || !s)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
			tab[k++] = ft_strndup(s + j, i - j);
	}
	tab[k] = NULL;
	return (tab);
}
