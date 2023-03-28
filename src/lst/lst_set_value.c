/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_set_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:28:22 by arforgea          #+#    #+#             */
/*   Updated: 2023/03/28 08:48:29 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minishell.h"

t_cmd	*cmd_set_valus(t_cmd *ptr, char *abs, char **full_cmd, char *cmd)
{
	if (!ptr)
		return (NULL);
	ptr->abs_path = abs;
	ptr->full_cmd = full_cmd;
	ptr->cmd = cmd;
	return (ptr);
}

t_rdir	*rdir_set_value(t_rdir *ptr, char *rdir, char *infile, char *outfile)
{
	if (!ptr)
		return (NULL);
	ptr->rdir = rdir;
	ptr->infile = infile;
	ptr->outfile = outfile;
	return (ptr);
}
