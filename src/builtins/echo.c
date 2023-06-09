/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:17:37 by arforgea          #+#    #+#             */
/*   Updated: 2023/06/07 17:38:26 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	print_word(char *str)
{
	int		i;
	char	tmp;

	i = 0;
	while (str[i])
	{
		if (str[i] && (str[i] == '\'' || str[i] == '\"'))
		{
			tmp = str[i];
			i++;
			while (str[i] && str[i] != tmp)
				ft_putchar_fd(str[i++], 1);
		}
		else if (str[i] && (str[i] != '\'' && str[i] != '\"'))
			ft_putchar_fd(str[i], 1);
		i++;
	}
}

void	ft_echo(char **tab)
{
	int		i;
	int		f;

	i = 1;
	f = 0;
	while (!ft_strncmp(tab[i], "-n", 2))
	{
		f = 1;
		i++;
	}
	while (tab[i])
	{
		print_word(tab[i]);
		if (tab[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (f != 1)
		ft_putchar_fd('\n', 1);
	g_status = 0;
}
