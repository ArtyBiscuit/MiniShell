/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:42:51 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/17 10:56:12 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

static int	is_special(char c)
{
	return (c == '<' || c == '>' || c == '|');
}

static void	add_no_spaces(char *str, char *res, int *i, int *j)
{
	char	tmp;

	tmp = str[*i];
	res[*j] = str[*i];
	(*j)++;
	(*i)++;
	while (str[*i] && str[*i] != tmp)
	{
		res[*j] = str[*i];
		(*j)++;
		(*i)++;
	}
}

char	*add_spaces(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * ((ft_strlen(str) * 2) + 1));
	while (str[i])
	{
		if (str[i] && (str[i] == '\"' || str[i] == '\''))
			add_no_spaces(str, res, &i, &j);
		if (str[i] && is_special(str[i]))
		{
			if (str[i - 1] && (str[i - 1] != ' ' && !is_special(str[i - 1])))
				res[j++] = ' ';
			res[j++] = str[i++];
		}
		if (i >= 0 && str[i] != str[i - 1] && is_special(str[i - 1]))
			res[j++] = ' ';
		res[j++] = str[i++];
	}
	res[j] = '\0';
	return (res);
}
