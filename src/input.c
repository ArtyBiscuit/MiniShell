/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:42:51 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/17 10:15:19 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

char	*add_spaces(char *str)
{
	int		i;
	int		j;
	char	tmp;
	char	*res;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * ((ft_strlen(str) * 2) + 1));
	while (str[i])
	{
		if (str[i] && (str[i] == '\"' || str[i] == '\''))
		{
			tmp = str[i];
			res[j++] = str[i++];
			while (str[i] && str[i] != tmp)
				res[j++] = str[i++]; 
		}
		if (str[i] && (str[i] == '<' || str[i] == '>' || str[i] == '|'))
		{
			if (str[i - 1] && (str[i - 1] != ' '
					&& str[i - 1] != '<' && str[i - 1] != '>'))
				res[j++] = ' ';
			res[j++] = str[i++];
		}
		if (i >= 0 && str[i] != str[i - 1] && (str[i - 1] == '<'
				|| str[i - 1] == '>' || str[i - 1] == '|'))
			res[j++] = ' ';
		res[j++] = str[i++];
	}
	res[j] = '\0';
	return (res);
}
