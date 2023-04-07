/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_abs_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:24:03 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/07 18:05:42 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

static char	*get_good_path(char *cmd, char **envp_path)
{
	char	*path_bin;
	char	*path_tmp;
	int		index;

	index = -1;
	if (!cmd)
		return (NULL);
	while (envp_path && envp_path[++index])
	{
		if (envp_path[index][ft_strlen(envp_path[index]) - 1] == '/')
			path_bin = ft_strjoin(envp_path[index], cmd);
		else
		{
			path_tmp = ft_strjoin(envp_path[index], "/");
			path_bin = ft_strjoin(path_tmp, cmd);
			free(path_tmp);
		}
		if (!access(path_bin, X_OK))
		{
			free_tab(envp_path);
			return (path_bin);
		}
		free(path_bin);
	}
	return (NULL);
}

char	*get_abs_path(char *cmd, char **envp)
{
	int		i;
	char	**envp_path;

	if (!cmd || !envp)
		return (NULL);
	if (!access(cmd, F_OK))
		return (cmd);
	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
	{
		if (!envp[i])
			return (NULL);
		i++;
	}
	envp_path = ft_split(envp[i], ':');
	return (get_good_path(cmd, envp_path));
}
