/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chevrons.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:35:54 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/06 18:01:29 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"
#include "libft/libft.h"

static t_rdir	*search_rlt_file(t_rdir *rdir, char *cmd, int i)
{
	char	*in;
	char	*out;
	t_rdir	*tmp;

	tmp = rdir;
	in = tmp->infile;
	out	= tmp->outfile;
	if (cmd[i] == '<')
	{
		in = get_next_word(&cmd[i]);
	}
	else
	{
		out	= get_next_word(&cmd[i]);
	}
	return (tmp);
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

t_rdir	*get_chevron(t_rdir *rdir, char *cmd)
{
	int		i;
	int		index;
	t_rdir	*tmp;

	i = 0;
	index = 0;
	tmp = rdir;
	while (tmp->next)
	{
		if (cmd[i] && (cmd[i] == '<' || cmd[i] == '>'))
		{
			tmp->rdir = refile_chevrons(&cmd[i]);
//			if (cmd[i + 1] == '<')
//				tmp->in = "le truc avec le heredoc";
			if (cmd[i] == '>' || cmd[i] == '<')
			{
				tmp = search_rlt_file(tmp, cmd, i);
			}
		}
		i++;
	}
	return (tmp);
}


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
