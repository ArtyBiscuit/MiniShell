/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtt_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 09:49:35 by axcallet          #+#    #+#             */
/*   Updated: 2023/05/05 10:42:06 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../inc/minishell.h"
#include <stdlib.h>

t_data	*dtt_init(t_data *data)
{
	t_exec			*dtt;
	t_exec			*tmp;
	int	cmp;

	dtt = NULL;
	dtt = malloc(sizeof(t_exec));
	if (!dtt)
		return (NULL);
	dtt->back = NULL;
	tmp = dtt;
	cmp = 1;
	while (cmp < get_pipes_number(data->input))
	{
		tmp->next = malloc(sizeof(t_exec));
		if (!tmp->next)
			return (NULL);
		tmp->next->back = tmp;
		tmp = tmp->next;
		cmp++;
	}
	tmp->next = NULL;
	data->dtt = dtt;
	data->nb_cmd = get_pipes_number(data->input);
	return (data);
}
