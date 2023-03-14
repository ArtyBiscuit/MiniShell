#include "../inc/mini_shell.h"
#include "libft/libft.h"
#include <unistd.h>

char	*get_abs_path(char *cmd, char **envp)
{
	int		i;
	char	**envp_path;

	if(!cmd || !envp)
		return (NULL);
	if(access(cmd, F_OK))
		return (cmd);
	i = 0;
	while(ft_strncmp(envp[i], "PATH=", 5))
	{
		if(!envp[i])
			return (NULL);
		i++;
	}
	envp_path = ft_split(envp[i], ':');
	
}

char	*get_good_path(char *cmd, char **envp_path)
{
	char	*path_bin;
	char	*path_tmp;
	int		index;

	if (!cmd)
		return (NULL);
	index = 0;
	while (envp_path && envp_path[index])
	{
		if (envp_path[index][ft_strlen(envp_path[index]) - 1] == '/')
			path_bin = ft_strjoin(envp_path[index], cmd);
		else
		{
			path_tmp = ft_strjoin(envp_path[index], "/");
			path_bin = ft_strjoin(path_tmp, cmd);
			free(path_tmp);
		}
		if (access(path_bin, X_OK) == 0)
		{
			free_tab(envp_path);
			return (path_bin);
		}
		free(path_bin);
		index++;
	}
	return (NULL);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int main(int argc, hcar **argv, char **envp)
{
	get_abs_path()
}
