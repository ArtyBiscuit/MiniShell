/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_argument.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:18:14 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/05 09:37:08 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"
#include <stdio.h>

int	skip_argument(char *c)
{
	int		index;
	char	temple;

	index = 1;
	temple = *c;
	while (c)
	{
		if (temple == c[index])
			return (index);
		index++;
	}
	return (-1);
}
