/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 04:42:11 by arforgea          #+#    #+#             */
/*   Updated: 2023/01/25 01:30:54 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	**get_path_var(char *envp[])
{
	char	**var_path;
	char	*tmp;
	size_t	tmp_size;
	int		index;

	index = 0;
	while (envp[index])
	{
		tmp = ft_strnstr(envp[index], "PATH", 4);
		if (tmp)
			break ;
		index++;
	}
	if (!tmp)
		return (NULL);
	tmp_size = ft_strlen(tmp);
	tmp = ft_substr(tmp, 5, tmp_size);
	var_path = ft_split(tmp, ':');
	free(tmp);
	return (var_path);
}

char	*get_good_path(char *cmd, char **lst_path)
{
	char	*path_bin;
	char	*path_tmp;
	int		index;

	if (!cmd)
		return (NULL);
	index = 0;
	while (lst_path && lst_path[index])
	{
		if (lst_path[index][ft_strlen(lst_path[index]) - 1] == '/')
			path_bin = ft_strjoin(lst_path[index], cmd);
		else
		{
			path_tmp = ft_strjoin(lst_path[index], "/");
			path_bin = ft_strjoin(path_tmp, cmd);
			free(path_tmp);
		}
		if (access(path_bin, X_OK) == 0)
			return (path_bin);
		free(path_bin);
		index++;
	}
	return (NULL);
}
