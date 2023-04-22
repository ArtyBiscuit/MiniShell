/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:58:12 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/22 15:02:39 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

char	*remove_extra_spaces(char *cmd)
{
    int 	i;
	int		j;
    char	*res;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (ft_strlen(cmd) + 1));
    while (cmd[i])
	{
        if (cmd[i] != ' ' || (i > 0 && cmd[i - 1] != ' '))
            res[j++] = cmd[i];
        i++;
    }
    res[j] = '\0';
    return res;
}
