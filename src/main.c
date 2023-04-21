/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:30:39 by axcallet          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/04/20 19:05:02 by arforgea         ###   ########.fr       */
=======
/*   Updated: 2023/04/19 13:47:02 by axcallet         ###   ########.fr       */
>>>>>>> 5a1816898956d83f6da7bf1b39ac66b2994d833b
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	t_data	*data;	

	data = malloc(sizeof(t_data));
	data->envp = envp;
	while (1)
	{
		data->input = readline("B==> ");
		add_history(data->input);
		if (data->input[0] == '\0')
			printf("%s", data->input);
		data->input = add_spaces(data->input);
		if (check_syntax(data->input))
		{
			printf("Syntax error\n");
<<<<<<< HEAD
		DB_print_tab(turbo_split(data->input, '|'));
		DB_print_tab(input_to_tab(data->input));
=======
			return (1);
		}
>>>>>>> 5a1816898956d83f6da7bf1b39ac66b2994d833b
		data = dtt_init(data);
		data = dtt_refile(data);
		free(data->input);
	}
	return (0);
}
