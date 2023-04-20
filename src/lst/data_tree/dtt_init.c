/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtt_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 09:49:35 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/20 18:54:46 by arforgea         ###   ########.fr       */
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
