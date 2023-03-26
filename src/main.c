/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:30:39 by axcallet          #+#    #+#             */
/*   Updated: 2023/03/26 07:54:17 by arty             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"
#include "libft/libft.h"

int	main(int argc, char **argv, char **envp)
{
	/////// CA LEAK !!!! ///////
	/*
	(void)argc;
	(void)argv;
	(void)envp;

	t_rdir *test;

	test = rdir_lst_init(3);

	while(test)
	{
		printf("%p\n", test);
		test = test->next;
	}
	rdir_lst_free(test);
	*/

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
	return (0);
}
