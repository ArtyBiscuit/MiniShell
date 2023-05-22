/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:30:42 by axcallet          #+#    #+#             */
/*   Updated: 2023/05/22 15:14:15 by axcallet         ###   ########.fr       */
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
/*
static int    replace_env_var(t_data *data, char *var_name, char *new_value)
{
    while (tmp)
    {
        if (!ft_strncmp(var_name, tmp->var, ft_strlen(var_name) + 1))
        {
            free(tmp->value);
            tmp->value = new_value;
            break ;
        }
        tmp = tmp->next;
    }
    return (0);
}
*/
int	ft_cd(t_data *data, t_exec *dtt)
{
	char	pwd[PATH_MAX];
	char	*tmp;
	t_exec	*ptr;

	ptr = dtt;
	if (!cd_errors(ptr))
	{
		getcwd(pwd, sizeof(pwd));
		ft_unset(&data->envp, "OLDPWD");
		tmp = ft_strjoin("OLDPWD=", pwd);
		ft_export(&data->envp, tmp);
		free(tmp);
		if (chdir(ptr->full_cmd[1]))
		{
			perror(ptr->full_cmd[1]);
			g_status = 1;
			return (1);
		}
		getcwd(pwd, sizeof(pwd));
		ft_unset(&data->envp, "PWD");
		tmp = ft_strjoin("PWD=", pwd);
		ft_export(&data->envp, tmp);
		free(tmp);
		return (0);
	}
	return (1);
}
