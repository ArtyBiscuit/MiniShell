/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 09:39:12 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/05 15:21:38 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

char	**split_pipes(char *str)
{
	int		i;
	int		j;
	int		index;
	char	**f_tab;

	i = 0;
	j = 0;
	index = 0;
	f_tab = malloc(sizeof(char *) * (get_pipes_number(str) + 1));
	if (!f_tab)
		return (NULL);
    //f_tab[get_pipes_number(str)] = NULL;
	while (i < get_pipes_number(str))
	{
		while (str[index])
		{
			if (str[index + j] == '"')
				j += skip_argument(&str[index + j]);
			if (str[index + j] == '|' || str[index + j] == '\0')
			{
				f_tab[i] = malloc(sizeof(char) * (j + 1));
				if (!f_tab[i])
					return (NULL);
				ft_memcpy(f_tab[i], &str[index], j);
				f_tab[i][j + index] = '\0';
				index += j + 1;
				break ;
			}
			j++;
		}
		i++;
		j = 0;
	}
	f_tab[i] = NULL;
	return (f_tab);
}

/*
char	**split_pipes(char *str)
{
	int	i;
	int j;
	int index;
	char	**f_tab;

	int yolo = get_pipes_number(str);

	f_tab = malloc(sizeof(char *) * (get_pipes_number(str) + 1));
	if (!f_tab)
		return (NULL);
	f_tab[get_pipes_number(str) + 1] = NULL;
	i = 0;
	j = 0;
	index = 0;
	while (i < get_pipes_number(str))
	{
		while(str[j + index])
		{
			if (str[index + j] == '"')
				j += skip_argument(&str[j]);
			if (str[index + j] == '|')
			{
				f_tab[i] = malloc(sizeof(char) * j);
				f_tab[i][j - index] = '\0';
				index = j;
				j = 0;
				break ;
			}
			j++;
		}
		i++;
	}
	return (f_tab);
}
*/
