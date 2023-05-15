/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:58:12 by axcallet          #+#    #+#             */
/*   Updated: 2023/05/10 13:24:36 by axcallet         ###   ########.fr       */
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
	res = malloc(sizeof(char) * (ft_strlen(cmd) + 2));
    while (cmd && cmd[i])
	{
        if (cmd[i] != ' ' || (i > 0 && cmd[i - 1] != ' '))
            res[j++] = cmd[i];
		i++;
    }
    res[j] = '\0';
	if (cmd)
		free(cmd);
    return (res);
}

void	add_no_spaces(char *cmd, char *new_cmd, int *i, int *j)
{
	char	tmp;

	tmp = cmd[*i];
	new_cmd[*j] = cmd[*i];
	(*j)++;
	(*i)++;
	while (cmd[*i] && cmd[*i] != tmp)
	{
		new_cmd[*j] = cmd[*i];
		(*j)++;
		(*i)++;
	}
	if (cmd[*i] == tmp)
		new_cmd[*j] = tmp;
}

