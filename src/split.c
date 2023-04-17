/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 09:39:12 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/12 15:36:18 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

static char	*get_str(char *str, int *index, int *j, char c)
{
	char	*f_tab;

	f_tab = NULL;
	while (str[*index])
	{
		if (str[*index + *j] == '"')
			*j += skip_argument(&str[*index + *j]);
		if (str[*index + *j] == c || str[*index + *j] == '\0')
		{
			f_tab = malloc(sizeof(char) * (*j + 1));
			if (!f_tab)
				return (NULL);
			ft_memcpy(f_tab, &str[*index], *j);
			f_tab[*j + *index] = '\0';
			*index += *j + 1;
			break ;
		}
		(*j)++;
	}
	return (f_tab);
}

char	**turbo_split(char *str, char c)
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
	while (i < get_pipes_number(str))
	{
		f_tab[i] = get_str(str, &index, &j, c);
		i++;
		j = 0;
	}
	f_tab[i] = NULL;
	return (f_tab);
}
