/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:41:40 by arforgea          #+#    #+#             */
/*   Updated: 2023/05/05 11:12:35 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

static int	str_is_blank(char *str)
{
	int	i;

	i = 0;
	if (str[i + 1])
		i++;
	while (str[i])
	{
		if (str[i] && !is_space(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_chevrons_syntax(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] && (str[i] == '\'' || str[i] == '\"'))
			i += skip_argument(&str[i]);
		if (str[i] && is_rdir(str[i]))
		{
			if (str[i + 1] && is_rdir(str[i + 1]) && str[i] != str[i + 1])
				return (1);
			if (str[i + 1] && str[i + 2]
				&& is_rdir(str[i + 1]) && is_rdir(str[i + 2]))
				return (1);
			if (str_is_blank(&str[i]))
				return (1);
		}
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
