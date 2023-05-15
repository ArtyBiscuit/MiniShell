/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:17:37 by arforgea          #+#    #+#             */
/*   Updated: 2023/05/12 09:22:30 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minishell.h"

void	echo(char *str, char *flags)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	while (flags && flags[i])
	{
		if (flags[i] == 'n')
			f = 1;
		i++;
	}
	ft_putstr_fd(str, 1);
	if (f)
		return ;
	write(1, "\n", 1);
}
