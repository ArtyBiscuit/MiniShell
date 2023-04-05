/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chevrons.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:35:54 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/05 09:35:57 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

static char	*search_rlt_file(char *cmd)
{
	int		i;
	int		j;
	char	*file;

	i = 0;
	j = 0;
	while (cmd[i])
	{
		while (cmd[i] && (cmd[i] == '<' || cmd[i] == '>'))
			i++;
		while (cmd[i] && (cmd[i] == ' ' || cmd[i] == '\t'))
			i++;
		file = malloc(sizeof(char) * strlen_word(&cmd[i]));
		while (cmd[i] && (cmd[i] != ' ' && cmd[i] != '\t'))
			file[j++] = cmd[i++];
		return (file);
	}
	return (NULL);
}

static char	*refile_chevrons(char *cmd)
{
	if (cmd[0] == '<')
	{
		if (cmd[1] == '<')
			return ("<<");
		return ("<");
	}
	else if (cmd[0] == '>')
	{
		if (cmd[1] == '>')
			return (">>");
		return (">");
	}
	return (NULL);
}
/*
t_cmd	*get_chevron(char *cmd)
{
	int		i;
	int		index;
	t_cmd	*tmp;

	i = 0;
	index = 0;
	tmp = malloc(sizeof(t_cmd));
	tmp->spe = malloc(sizeof(char *) * get_chevrons_numbers(cmd));
	while (cmd[i])
	{
		if (cmd[i] && (cmd[i] == '<' || cmd[i] == '>'))
		{
			tmp->spe[index++] = refile_chevrons(&cmd[i]);
			if (cmd[i + 1] == '<')
				tmp->in = "le truc avec le heredoc";
			else if (cmd[i] == '>')
				tmp->out = search_rlt_file(&cmd[i]);
			else if (cmd[i] == '<')
				tmp->in = search_rlt_file(&cmd[i]);
		}
		i++;
	}
	return (tmp);
}
*/

int	check_chevrons(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] && (str[i] == '>' || str[i] == '<'))
			return (1);
		i++;
	}
	return (0);
}
