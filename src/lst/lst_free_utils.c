/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_free_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:37:47 by arforgea          #+#    #+#             */
/*   Updated: 2023/03/28 08:48:16 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minishell.h"

void	cmd_link_value_free(t_cmd *ptr)
{
	if (!ptr)
		return ;
	if (ptr->abs_path)
		free(ptr->abs_path);
	if (ptr->full_cmd)
		free(ptr->full_cmd);
	if (ptr->cmd)
		free(ptr->cmd);
	return ;
}

void	rdir_link_value_free(t_rdir *ptr)
{
	if (!ptr)
		return ;
	if (ptr->infile)
		free(ptr->infile);
	if (ptr->outfile)
		free(ptr->outfile);
	if (ptr->rdir)
		free(ptr->rdir);
	return ;
}

void	rdir_lst_free(t_rdir *ptr)
{
	t_rdir	*next;
	t_rdir	*current;

	current = ptr;
	while (current)
	{
		next = current->next;
		rdir_link_value_free(ptr);
		free(current);
		current = next;
	}
	return ;
}

void	exec_lst_free(t_exec *ptr)
{
	t_exec	*next;
	t_exec	*current;

	current = ptr;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	return ;
}

void	lst_destroy(t_exec *ptr)
{
	t_exec	*next;
	t_exec	*current;

	current = ptr;
	while(current)
	{
		next = current->next;
		if(current->rdir)
			rdir_lst_free(current->rdir);
		else if (current->cmd)
		{
			cmd_link_value_free(current->cmd);
			free(current->cmd);
		}
		current = next;
	}
	exec_lst_free(ptr);
	return ;
}
