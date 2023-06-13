/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:05:10 by arforgea          #+#    #+#             */
/*   Updated: 2023/06/13 11:05:07 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	print_tab(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		ft_putstr_fd("declare -X ", 1);
		while (array[i][j])
		{
			if (array[i][j] == '=')
			{
				ft_putchar_fd(array[i][j], 1);
				ft_putchar_fd('\"', 1);
				while (array[i][j])
					ft_putchar_fd(array[i][j++], 1);
				ft_putchar_fd('\"', 1);
			}
			if (array[i][j])
				ft_putchar_fd(array[i][j++], 1);
		}
		ft_putchar_fd('\n', 1);
		i++;
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
