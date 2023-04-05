/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtt_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 09:49:35 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/05 17:31:47 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../inc/minishell.h"
#include <stdlib.h>

t_data	*dtt_init(t_data *data)
{
	int		i;
	char	**tab;
	t_exec	*tmp;

	i = 0;
	data->dtt = exec_lst_init(get_pipes_number(data->input));
	if (!data->dtt)
		return (NULL);
	tmp = data->dtt;
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
