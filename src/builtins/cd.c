/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:30:42 by axcallet          #+#    #+#             */
/*   Updated: 2023/06/02 15:40:32 by axcallet         ###   ########.fr       */
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

static void	change_vars(char ***envp, char *var)
{
	char	pwd[PATH_MAX];
	char	**tmp;

	tmp = malloc(sizeof(char *) * 3);
	tmp[0] = ft_strdup("export");
	getcwd(pwd, sizeof(pwd));
	tmp[1] = ft_strjoin(var, pwd);
	tmp[2] = NULL;
	ft_export(envp, tmp);
	free_tab(tmp);
}

int	ft_cd(t_data *data, t_exec *dtt)
{
	t_exec	*ptr;

	ptr = dtt;
	if (!cd_errors(ptr))
	{
		change_vars(&data->envp, "OLDPWD=");
		if (chdir(ptr->full_cmd[1]))
		{
			perror(ptr->full_cmd[1]);
			g_status = 1;
			return (1);
		}
		change_vars(&data->envp, "PWD=");
		return (0);
	}
	return (1);
}
