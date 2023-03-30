/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:15:24 by axcallet          #+#    #+#             */
/*   Updated: 2023/03/28 11:36:10 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

int	parsing(char *input)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(input, '|');
	while (tab[i])
	{
		if (get_chevron(tab[i]) == NULL)
			return (1);
		i++;
	}
	return (0);
}
