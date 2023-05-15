#include "../../inc/minishell.h"

int	get_var_size(char *str)
{
	int	index;
	int	size;

	size = 0;
	index = 0;
	while (str[index])
	{
		if (str[index] == '"' || str[index] == '\'')
		{
			index++;
			continue ;
		}
		index++;
		size++;
	}
	return (size);
}

int get_env_size(char **envp)
{
	int	index;

	index = 0;
	while (envp[index])
		index++;
	return (index);
}
