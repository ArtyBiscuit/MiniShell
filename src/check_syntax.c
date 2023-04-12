/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:41:40 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/12 10:40:00 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

static int	check_chevrons_syntax(char *str)
{
	int	nbr;
	int cmp;

	cmp = 0;
	nbr = 0;
	while (str[cmp])
	{
		if (str[cmp] == '<' || str[cmp] == '>')
			nbr++;
		if (nbr > 2)
			return (1);
		if (str[cmp] != ' ' || str[cmp] != '	')
			nbr = 0;
		cmp++;
	}
	return (0);
}

static int	check_pipes_syntax(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
		{
			i++;
			while(str[i] && str[i] != '|'  && (str[i] == ' ' || str[i] == '	'))
			 i++;
			if (!str[i] || str[i] == '|')
				return(1);
		}
		i++;
	}
	return(0);
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

/*
 *	wc -l |                        
 *	oui >>> non
 *	echo "et oui | echo "les amis !"
 *	NULL
 *
 */
