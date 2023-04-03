/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:30:39 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/03 09:39:09 by axcallet         ###   ########.fr       */
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
	int		i = 0;
	char	**tab;

	tab = split_pipes("echo \"prout | lol\" | hello");
	while (tab[i] != NULL)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
//	t_exec	*exec = exec_lst_init(50);
//	t_exec	*tmp = exec;
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
