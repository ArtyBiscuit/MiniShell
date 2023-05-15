/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:04:56 by axcallet          #+#    #+#             */
/*   Updated: 2023/05/15 17:10:07 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minishell.h"

int ft_env(t_exec *dtt, char **envp)
{
	if (dtt->full_cmd[1])
	{
		perror(dtt->full_cmd[1]);
		g_status = 1;
		return (1);
	}
	print_tab(envp);
	return (0);
}
