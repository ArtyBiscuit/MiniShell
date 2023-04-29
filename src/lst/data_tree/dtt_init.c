/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtt_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 09:49:35 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/29 15:06:54 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../inc/minishell.h"
#include <stdlib.h>

t_data	*dtt_init(t_data *data)
{
	t_exec			*dtt;
	t_exec			*tmp;
	unsigned int	cmp;
	unsigned int	dtt_size;

	dtt_size = get_pipes_number(data->input);
	dtt = NULL;
	if(!(dtt = malloc(sizeof(t_exec) * 1)))
		return (NULL);
	dtt->back = NULL;
	tmp = dtt;
	cmp = 1;
	while(cmp < dtt_size)
	{
		 	if(!(tmp->next = malloc(sizeof(t_exec) * 1)))
				return (NULL);
			tmp->next->back = tmp;
			tmp = tmp->next;
			cmp++;
	}
	tmp->next = NULL;
	data->dtt = dtt;
	data->nb_cmd = dtt_size;
	return (data);
}
