/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:42:51 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/22 14:52:28 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

static void	add_no_spaces(char *cmd, char *new_cmd, int *i, int *j)
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
}

static void	inheritance_rdir(char *cmd, char *new_cmd, int *i, int *j)
{
	if (i > 0 && cmd[*i - 1] != ' ' && !is_rdir(cmd[*i - 1])
		&& cmd[*i - 1] != '|')
		new_cmd[*j++] = ' ';
	new_cmd[*j++] = cmd[*i++];
}

char	*add_spaces_rdir(char *cmd)
{
	int		i;
	int		j;
	char	*new_cmd;

	i = 0;
	j = 0;
	new_cmd = malloc(sizeof(char) * ((ft_strlen(cmd) * 2) + 1));
	if (!new_cmd)
		return (NULL);
	while (cmd[i])
	{
		if (cmd[i] && (cmd[i] == '\"' || cmd[i] == '\''))
			add_no_spaces(cmd, new_cmd, &i, &j);
		if (cmd[i] && is_rdir(cmd[i]))
			inheritance_rdir(cmd, new_cmd, &i, &j);
		if (cmd[i] && i > 0 && !is_space(cmd[i])
			&& !is_rdir(cmd[i]) && is_rdir(cmd[i - 1]))
			new_cmd[j++] = ' ';
		if (cmd[i])
			new_cmd[j++] = cmd[i++];
	}
	new_cmd[j] = '\0';
	return (new_cmd);
}

static void	inheritance_pipes(char *cmd, char *res, int *i, int *j)
{
	while (*j > 0 && res[*j - 1] == ' ')
		(*j)--;
	res[*j++] = '|';
	while (cmd[*i + 1] == ' ')
		(*i)++;
}

char	*remove_spaces_pipes(char *cmd)
{
	int		i;
	int		j;
	int		in_quotes;
	char	*res;

	i = -1;
	j = 0;
	in_quotes = 0;
	res = malloc(sizeof(char) * (ft_strlen(cmd) + 1));
	if (!res)
		return (NULL);
	while (cmd[i++] != '\0')
	{
		if (cmd[i] == '\"')
			in_quotes = !in_quotes;
		else if (cmd[i] == '|' && !in_quotes)
			inheritance_pipes(cmd, res, &i, &j);
		else
			res[j++] = cmd[i];
	}
	res[j] = '\0';
	return (res);
}
