/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:30:42 by axcallet          #+#    #+#             */
/*   Updated: 2023/05/31 10:33:32 by axcallet         ###   ########.fr       */
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
	t_exec	*ptr;

	ptr = dtt;
	if (!cd_errors(ptr))
	{
		getcwd(pwd, sizeof(pwd));
		ft_unset(&data->envp, "OLDPWD");
		ft_export(&data->envp, ft_strjoin("OLDPWD=", pwd));
		if (chdir(ptr->full_cmd[1]))
		{
			perror(ptr->full_cmd[1]);
			g_status = 1;
			return (1);
		}
		getcwd(pwd, sizeof(pwd));
		ft_unset(&data->envp, "PWD");
		ft_export(&data->envp, ft_strjoin("PWD=", pwd));
		return (0);
	}
	return (1);
}
