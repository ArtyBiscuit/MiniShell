/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:42:51 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/19 15:15:35 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

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

char	*add_spaces(char *cmd)
{
	int		i;
	int		j;
	char	*new_cmd;

	i = 0;
	j = 0;
	new_cmd = malloc(sizeof(char) * ((ft_strlen(cmd) * 2) + 1));
	while (cmd[i])
	{
		if (cmd[i] && (cmd[i] == '\"' || cmd[i] == '\''))
			add_no_spaces(cmd, new_cmd, &i, &j);
		if (cmd[i] && is_rdir(cmd[i]))
		{
			if (i > 0 && cmd[i - 1] != ' ' && !is_rdir(cmd[i - 1])
				&& cmd[i - 1] != '|')
				new_cmd[j++] = ' ';
			new_cmd[j++] = cmd[i++];
		}
		if (cmd[i] && i > 0 && !is_rdir(cmd[i]) && is_rdir(cmd[i - 1]))
			new_cmd[j++] = ' ';
		if (cmd[i])
			new_cmd[j++] = cmd[i++];
	}
	new_cmd[j] = '\0';
	return (new_cmd);
}
