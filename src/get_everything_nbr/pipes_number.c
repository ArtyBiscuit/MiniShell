/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:00:01 by axcallet          #+#    #+#             */
/*   Updated: 2023/03/28 11:54:33 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minishell.h"

int	get_pipes_number(char *str)
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
		if (str[i] && str[i] == '|')
			res++;
		i++;
	}
	return (res + 1);
}

