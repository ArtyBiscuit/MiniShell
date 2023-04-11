/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:41:40 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/11 11:18:14 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"
#include <stddef.h>
#include <stdio.h>

static int	check_pipes_syntax(char *str);
static int	check_chevrons_syntax(char *str);

int	check_syntax(char *str)
{
	if (!str)
		return(1);
	if (get_chars_number(str, '"') % 2)
		return (1);
	if (check_pipes_syntax(str))
		return (1);
	if (check_chevrons_syntax(str))
		return (1);
	return (0);
}

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
	int	cmp;
	int	size;

	cmp = 0;
	size = ft_strlen(str);
	while(cmp)
	{
		if(str[cmp] == '|')
			return (1);
		if(str[cmp] != ' ' && str[cmp] != '	')
			return (0);
		else
			cmp--;
	}
	return(1);
}

/*
 *	wc -l |                        
 *	oui >>> non
 *	echo "et oui | echo "les amis !"
 *	NULL
 *
 */