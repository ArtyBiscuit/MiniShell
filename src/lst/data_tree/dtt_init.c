/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtt_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 09:49:35 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/07 13:54:04 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../inc/minishell.h"
#include <stdlib.h>

t_data	*dtt_init(t_data *data)
{
	t_data	*tmp;

	tmp = data;
	tmp->dtt = malloc(sizeof(t_exec) * get_pipes_number(tmp->input));
	if (!tmp->dtt)
	{
		write(2, "Error: dtt_init.", 16);
		return (NULL);
	}
	return (tmp);
}
	/*
	tab = split_pipes(data->input);
	while (tab[i])
	{
		if (check_chevrons(tab[i]))
		{
			tmp->rdir = rdir_lst_init(get_chevrons_number(tab[i]));
			if (!tmp->rdir)
				return (NULL);
		}
		else
		{
			tmp->cmd = malloc(sizeof(t_cmd) * 1);
			if (!tmp->cmd)
				return (NULL);
		}
		tmp = tmp->next;
		i++;
	}
//	free_tab(tab);
	return (data);
}
*/
