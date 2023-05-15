#include "../../inc/minishell.h"

static int	compare(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] != '=' && s2[i] == s1[i])
		i++;
	if (s2[i] == '=')
		return (1);
	return (0);
}

static int remove_string(char ***arr, char *str)
{
	char	**new_envp;
	int		i;
	int		j;

	new_envp = malloc(sizeof(char *) * (get_env_size((*arr))));
	if (!new_envp)
		return (1);
	i = 0;
	j = 0;
	while ((*arr)[i] != NULL)
	{
		if (compare(str, (*arr)[i]))
		{
			i++;
			continue;
		}
		new_envp[j] = ft_strdup((*arr)[i]);
		j++;
		i++;
	}
	new_envp[get_env_size((*arr)) - 1] = NULL;
	free_tab((*arr));
	*arr = new_envp;
	return (0);
}

int	ft_unset(char ***envp, char *str)
{
	int		i;
	int		good;

	i = 0;
	good = -1;
	if (!str)
	{
		printf("unset: not enough arguments");
		return (1);
	}
	while ((*envp)[i])
	{
		if (compare(str, (*envp)[i]))
			good = 1;
		i++;
	}
	if (good == 1)
		remove_string(envp, str);
	return (0);
}
