/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:41:07 by axcallet          #+#    #+#             */
/*   Updated: 2023/05/15 18:32:34 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minishell.h"

int	check_builtins(t_data *data, t_exec *dtt)
{
	if (!ft_strncmp(dtt->cmd, "echo", 4))
//		ft_echo(dtt);
		printf("builtins : echo\n");
	else if (!ft_strncmp(dtt->cmd, "cd", 2))
		ft_cd(data, dtt);
	else if (!ft_strncmp(dtt->cmd, "pwd", 3))
		ft_pwd(dtt);
	else if (!ft_strncmp(dtt->cmd, "export", 6))
		ft_export(&data->envp, dtt->full_cmd[1]);
	else if (!ft_strncmp(dtt->cmd, "unset", 5))
		ft_unset(&data->envp, dtt->full_cmd[1]);
	else if (!ft_strncmp(dtt->cmd, "env", 3))
		ft_env(dtt, data->envp);
	else if (!ft_strncmp(dtt->cmd, "exit", 4))
		ft_exit(data, dtt);
	else
		return (0);
	return (1);
}
