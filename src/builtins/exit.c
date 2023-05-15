/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:23:01 by axcallet          #+#    #+#             */
/*   Updated: 2023/05/15 11:21:24 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minishell.h"

static int	exit_error(char **tab)
{
	if (!tab[1])
		return (0);
	if (ft_str_isdigit(tab[1]))
	{
		ft_putstr_fd("exit : numeric argument required\n", 2);
		return (2);
	}
	if (tab[2])
	{
		ft_putstr_fd("exit : too many arguments\n", 2);
		return (1);
	}
	return (atoi(tab[1]));
}

int	ft_exit(t_data *data, t_exec *dtt)
{
	int	status;

	status = exit_error(dtt->full_cmd);
	lst_destroy(dtt);
	clear_history();
	if (data->input)
		free(data->input);
	if (data)
		free(data);
	ft_putstr_fd("exit\n", 1);
	exit(status);
}
