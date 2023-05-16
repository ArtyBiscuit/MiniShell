/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:05:10 by arforgea          #+#    #+#             */
/*   Updated: 2023/05/16 17:18:03 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minishell.h"

void	print_tab(char **arrey)
{
	int index;

	index = 0;
	while (arrey[index])
	{
		printf("declare -x %s\n", arrey[index]);
		index++;
	}
	return ;
}

void	print_tab_sort(char **tab)
{
	char	**tab_tmp;
	int		index;
	char	*tmp;

	index = 0;
	tab_tmp = ft_tab_dup(tab); 
	while (tab_tmp[index] && tab_tmp[index + 1])
	{
		if (ft_strncmp(tab_tmp[index], tab_tmp[index + 1], 10) > 0)
		{
			tmp = tab_tmp[index];
			tab_tmp[index] = tab_tmp[index + 1];
			tab_tmp[index + 1] = tmp;
			index = 0;
			continue ;
		}
		index++;
	}
	print_tab(tab_tmp);
	free_tab(tab_tmp);
	return ;
}
