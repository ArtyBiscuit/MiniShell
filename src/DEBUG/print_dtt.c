/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dtt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:04:46 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/21 18:42:48 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minishell.h"
#include <stdio.h>

void	DB_print_dtt(t_data *data)
{
	int		index;
	t_exec	*dtt;

	dtt = data->dtt;
	printf("***** DEBUG *****\n");
	printf("dtt: %p\n", dtt);
	while(dtt)
	{
		printf("\n\n");
		printf("fd_in = %d\nfd_out = %d\nabs_path = %s\n", dtt->fd_in, dtt->fd_out, dtt->abs_path);
		index = 0;
		printf("--- **full_cmd ---\n");
		if(dtt->full_cmd)
		{
			while(dtt->full_cmd[index])
			{
				printf("\tindex[%d]: %s\n", index, dtt->full_cmd[index]);
				index++;
			}
		}
		printf("cmd = %s\n", dtt->cmd);
		printf("dtt_next = %p\n", dtt->next);
		printf("dtt_back = %p\n", dtt->back);
		dtt = dtt->next;
	}
	printf("***** DEBUG *****\n");
}
