/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chevron_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:34:31 by axcallet          #+#    #+#             */
/*   Updated: 2023/03/28 11:55:20 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minishell.h"

int	get_chevrons_number(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] && (str[i] == '\"' || str[i] == '\''))
		{
			if (skip_argument(&str[i]))
				i += skip_argument(&str[i]);
		}
		if (str[i] && (str[i] == '<' || str[i] == '>'))
		{
			if (str[i] && (str[i + 1] == '<' || str[i + 1] == '>'))
				i += 2;
			else
				i++;
			res++;
		}
	}
	return (res);
}

