/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:58:18 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/20 19:03:53 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	DB_print_tab(char **tab)
{
	unsigned int	index;

	index = 0;
		printf("***** DEBUG *****\n");
	while(tab[index])
	{
		printf("%s\n", tab[index]);
		index++;
	}
		printf("***** DEBUG *****\n");
}
