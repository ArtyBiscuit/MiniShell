/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:13:28 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/20 18:57:34 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

static int	get_new_size(char *str)
{
	unsigned int	index;
	unsigned int	s_size;

	index = 0;
	s_size = 0;
	while(str[index])
	{
		if(str[index] == '"')
			index++;
		else
		{
			index++;
			s_size++;
		}
	}
	return (s_size);
}

static char	*refactor_str(char *str)
{
	unsigned int	index;
	unsigned int	new_index;
	char			*new_str;

	if(!(new_str = malloc(sizeof(char) * get_new_size(str))))
	{
		write(2, "Error: refactor_str.", 20);
		return (NULL);
	}
	index = 0;
	new_index = 0;
	while(str[index])
	{
		if(str[index] == '"')
			index++;
		new_str[new_index] = str[index];
		index++;
		new_index++;
	}
	return (new_str);
}

char	**input_to_tab(char *input)
{
	char				**f_tab;
	char				*str_tmp;
	unsigned int		index;

	if(!(f_tab = turbo_split(input, '|')))
	{
		write(2, "Error: input_to_tab.", 20);
		return (NULL);
	}
	index = 0;
	while(f_tab[index])
	{
		str_tmp = refactor_str(f_tab[index]);
		free(f_tab[index]);
		f_tab[index] = str_tmp;
		index++;
	}
	return (f_tab);
}
