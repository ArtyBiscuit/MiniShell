/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:30:42 by axcallet          #+#    #+#             */
/*   Updated: 2023/05/15 18:46:51 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minishell.h"
/*
static void	replace_env_var(t_data *data, char *var, char *new)
{
	int	i;

	i = 0;
	while (data->envp[i])
	{
		if (!ft_strncmp(data->envp[i], var, ft_strlen(var)))
		{
			data->envp[i] = ft_strdup(new);
			return ;
		}
		i++;
	}
}
*/
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
		//replace_env_var(data, "OLDPWD=", ft_strjoin("OLDPWD=", pwd));
		if (chdir(ptr->full_cmd[1]))
		{
			perror(ptr->full_cmd[1]);
			g_status = 1;
			return (1);
		}
		getcwd(pwd, sizeof(pwd));
		ft_unset(&data->envp, "PWD");
		ft_export(&data->envp, ft_strjoin("PWD=", pwd));
		//free(test);
		//replace_env_var(data, "PWD=", ft_strjoin("PWD=", pwd));
		return (0);
	}
	return (1);
}
