/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:17:37 by arforgea          #+#    #+#             */
/*   Updated: 2023/06/01 17:02:53 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minishell.h"

void	ft_echo(char **tab)
{
	int	i;
	int	f;

	i = 1;
	f = 0;
	while (!ft_strncmp(tab[i], "-n", 2))
	{
		f = 1;
		i++;
	}
	while (tab[i])
	{
		printf("%s", tab[i]);
		if (tab[i + 1])
			printf(" ");
		i++;
	}
	if (f != 1)
		printf("\n");
	g_status = 0;
}
