/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dtt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:04:46 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/22 19:07:41 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minishell.h"
#include <stdio.h>

void	DB_print_dtt(t_data *data)
{
	int		index;
	t_exec	*tmp;

	index = 0;
	tmp = data->dtt;
	printf("***** DEBUG *****\n");
	printf("dtt: %p\n", tmp);
	while(tmp)
	{
		printf("\n");
		printf("fd_in = %d\nfd_out = %d\nabs_path = %s\n", tmp->fd_in, tmp->fd_out, tmp->abs_path);
		index = 0;
		printf("--- **full_cmd ---\n");
		if(tmp->full_cmd)
		{
			while(tmp->full_cmd[index])
			{
				printf("index[%d]: %s\n", index, tmp->full_cmd[index]);
				index++;
			}
		}
		printf("cmd = %s\n", tmp->cmd);
		printf("dtt_next = %p\n", tmp->next);
		printf("dtt_back = %p\n", tmp->back);
		tmp = tmp->next;
	}
	printf("***** DEBUG *****\n");
}
