/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:41:40 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/17 11:52:14 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

static int	is_rdir(char c)
{
	return (c == '<' || c == '>');
}

static int	is_space(char c)
{
	return (c == ' ' || c == '	');
}

static int	check_chevrons_syntax(char *str)
{
	int	i;
	int	nbr;

	nbr = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == '\'')
			i += skip_argument(&str[i]);
		if (is_rdir(str[i]))
		{
			while (is_rdir(str[i]) || is_space(str[i]))
			{
				if (is_rdir(str[i]))
					nbr++;
				i++;
			}
		}
		if (nbr > 2)
			return (1);
		else
			nbr = 0;
		i++;
	}
	return (0);
}

static int	check_pipes_syntax(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '|' && (str[i] == ' ' || str[i] == '	'))
		i++;
	if (str[i] == '|')
		return (1);
	while (str[i])
	{
		if (str[i] == '|')
		{
			i++;
			while (str[i] && str[i] != '|' && (str[i] == ' ' || str[i] == '	'))
				i++;
			if (!str[i] || str[i] == '|')
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_syntax(char *str)
{
	if (!str)
		return (1);
	if (get_chars_number(str, '"') % 2)
		return (1);
	if (check_pipes_syntax(str))
		return (1);
	if (check_chevrons_syntax(str))
		return (1);
	return (0);
}
