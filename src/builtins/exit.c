/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:23:01 by axcallet          #+#    #+#             */
/*   Updated: 2023/06/05 16:28:30 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minishell.h"

static int	check_is_numeric(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-')
		i++;
	while (num[i])
	{
		if (num[i] && !ft_isdigit(num[i]))
			return (1);
		i++;
	}
	return (0);
}

static long long	exit_error(char **tab)
{
	if (!tab[1])
		return (0);
	if (check_is_numeric(tab[1]))
	{
		ft_putstr_fd("exit : numeric argument required\n", 2);
		return (2);
	}
	if (tab[2])
	{
		ft_putstr_fd("exit : too many arguments\n", 2);
		return (1);
	}
	return (ft_atoll(tab[1]));
}

int	ft_exit(t_data *data, t_exec *dtt)
{
	long long	status;

	status = exit_error(dtt->full_cmd);
	clear_history();
	if (data->input)
		free(data->input);
	if (data->tab_pid)
		free(data->tab_pid);
	if (data->envp)
		free_tab(data->envp);
	if (data)
		free(data);
	if ((status == -1 || status == 0) && ft_strlen(dtt->full_cmd[1]) > 2)
	{
		ft_putstr_fd("exit : numeric argument required\n", 2);
		lst_destroy(dtt);
		exit(2);
	}
	lst_destroy(dtt);
	ft_putstr_fd("exit\n", 1);
	exit(status % 256);
}
