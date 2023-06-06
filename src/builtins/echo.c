/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:17:37 by arforgea          #+#    #+#             */
/*   Updated: 2023/06/06 18:00:20 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minishell.h"

void	ft_echo(char **tab)
{
	int		i;
	int		j;
	int		f;
	char	tmp;

	i = 1;
	j = 0;
	f = 0;
	while (!ft_strncmp(tab[i], "-n", 2))
	{
		f = 1;
		i++;
	}
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] && (tab[i][j] == '\'' || tab[i][j] == '\"'))
			{
				tmp = tab[i][j];
				j++;
				while (tab[i][j] && tab[i][j] != tmp)
					ft_putchar_fd(tab[i][j++], 1);
			}
			else if (tab[i][j] && (tab[i][j] != '\'' && tab[i][j] != '\"'))
				ft_putchar_fd(tab[i][j], 1);
			j++;
		}
		ft_putchar_fd(' ', 1);
		i++;
	}
	if (f != 1)
		ft_putchar_fd('\n', 1);
	g_status = 0;
}
