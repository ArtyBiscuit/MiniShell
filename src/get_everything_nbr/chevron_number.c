/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chevron_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:34:31 by axcallet          #+#    #+#             */
/*   Updated: 2023/03/28 11:37:05 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minishell.h"

int	get_chevrons_numbers(char *cmd)
{
	int	i;
	int	nb;

	i = -1;
	nb = 0;
	while (cmd[++i])
	{
		if (cmd[i] && ((cmd[i] == '<' || cmd[i] == '>')
				&& (cmd[i + 1] != '<' && cmd[i + 1] != '>')))
		{
			i++;
			nb++;
		}
		else if (cmd[i] && (cmd[i] == '<' && cmd[i + 1] == '<'))
		{
			i += 2;
			nb++;
		}
		else if (cmd[i] && (cmd[i] == '>' && cmd[i + 1] == '>'))
		{
			i += 2;
			nb++;
		}
	}
	return (nb);
}

