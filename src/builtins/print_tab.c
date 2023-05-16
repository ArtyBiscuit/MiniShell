/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:05:10 by arforgea          #+#    #+#             */
/*   Updated: 2023/05/16 14:05:14 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minishell.h"

void	print_tab(char **arrey)
{
	int index;

	index = 0;
	while (arrey[index])
	{
		printf("%s\n", arrey[index]);
		index++;
	}
	return ;
}

void	print_tab_sort(char **tab)
{
	int		index;
	char	*tmp;

	index = 0;
	while (tab[index] && tab[index + 1])
	{
		if (ft_strncmp(tab[index], tab[index + 1], 10) > 0)
		{
			tmp = tab[index];
			tab[index] = tab[index + 1];
			tab[index + 1] = tmp;
			index = 0;
			continue ;
		}
		index++;
	}
	print_tab(tab);
	return ;
}
