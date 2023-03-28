/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 08:54:27 by arforgea          #+#    #+#             */
/*   Updated: 2023/03/28 09:07:31 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"
#include <stdlib.h>

// D.T.T or "dtt" for "DaTa_Tree"

t_exec *dtt_init(char *str)
{
	t_exec	*data_tree;

	data_tree = malloc(sizeof(t_exec) * get_chevrons_numbers(str) + 1);
	return (data_tree);
}
