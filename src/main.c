/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:30:39 by axcallet          #+#    #+#             */
/*   Updated: 2023/03/26 12:09:03 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"
#include "libft/libft.h"
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;

	t_exec	*exec = exec_lst_init(50);
	t_exec	*tmp = exec;

	while(tmp)
	{
		printf("%p\n", tmp);
		tmp = tmp->next;
	}

	lst_destroy(exec);
	/*
	t_data	*data;	
	char	*input;

	data = malloc(sizeof(t_data));
	data->ac = argc;
	data->av = argv;
	data->env = envp;
	while (1)
	{
		input = readline("B==>");
		add_history(input);
		if (input[0] == '\0')
			printf("%s", input);
		else
		{
			if (parsing(input) == 1)
			{
				ft_putstr_fd("Error parsing", 2);
				return (1);
			}
		}
		free(input);
	}
	*/
	return (0);
}
