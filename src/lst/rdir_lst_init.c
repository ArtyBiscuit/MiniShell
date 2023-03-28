/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdir_lst_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 10:11:21 by arforgea          #+#    #+#             */
/*   Updated: 2023/03/28 08:48:39 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minishell.h"

static	t_rdir	*rdir_link_create(void)
{
	t_rdir	*current;

	current = malloc(sizeof(t_rdir) * 1);
	if (!current)
	{
		write(2, "Error: rdir_link_create.\n", 25);
		return (NULL);
	}
	current->next = NULL;
	current->back = NULL;
	current->rdir = NULL;
	current->infile = NULL;
	current->outfile = NULL;
	return (current);
}

static	t_rdir	*rdir_lst_add(t_rdir *current)
{
	t_rdir	*tmp;

	if (!current)
	{
		write(2, "Error: rdir_lst_add.\n", 21);
		return (NULL);
	}
	tmp = rdir_link_create();
	if (!tmp)
		return (NULL);
	tmp->back = current;
	current->next = tmp;
	return (tmp);
}

t_rdir	*rdir_lst_init(int nbr)
{
	t_rdir	*lst;
	t_rdir	*tmp;

	if (nbr <= 0)
	{
		write(2, "Error: rdir_lst_init.\n", 22);
		return (NULL);
	}
	lst = rdir_link_create();
	tmp = lst;
	nbr--;
	while (nbr)
	{
		tmp = rdir_lst_add(tmp);
		if (!tmp)
		{
			rdir_lst_free(lst);
			return (NULL);
		}
		nbr--;
	}
	return (lst);
}