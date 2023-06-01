/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:30:42 by axcallet          #+#    #+#             */
/*   Updated: 2023/06/01 17:08:35 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minishell.h"

static int	cd_errors(t_exec *ptr)
{
	if (ptr->full_cmd && ptr->full_cmd[2])
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		g_status = 1;
		return (1);
	}
	return (0);
}

int	ft_cd(t_data *data, t_exec *dtt)
{
	char	pwd[PATH_MAX];
	char	**tmp;
	t_exec	*ptr;

	tmp = malloc(sizeof(char*) * 3);
	tmp[0] = ft_strdup("export");
	tmp[2] = NULL;
	ptr = dtt;
	if (!cd_errors(ptr))
	{
		getcwd(pwd, sizeof(pwd));
		tmp[1] = ft_strjoin("OLDPWD=", pwd);
		ft_export(&data->envp, tmp);
		free(tmp[1]);
		if (chdir(ptr->full_cmd[1]))
		{
			perror(ptr->full_cmd[1]);
			free_tab(tmp);
			g_status = 1;
			return (1);
		}
		getcwd(pwd, sizeof(pwd));
		tmp[1] = ft_strjoin("PWD=", pwd);
		ft_export(&data->envp, tmp);
		free_tab(tmp);
		return (0);
	}
	free_tab(tmp);
	return (1);
}
