/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:23:52 by axcallet          #+#    #+#             */
/*   Updated: 2023/05/15 11:33:25 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minishell.h"

int	ft_pwd(t_exec *dtt)
{
	char	pwd[PATH_MAX];	
	
	if (dtt->full_cmd[1])
	{
		ft_putstr_fd("pwd: too many arguments\n", 2);
		g_status = 0;
		return (1);
	}
	getcwd(pwd, sizeof(pwd));
	ft_putstr_fd(pwd, 1);
	ft_putstr_fd("\n", 1);
	g_status = 0;
	return (1);
}
