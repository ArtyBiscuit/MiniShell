/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:30:39 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/22 13:19:35 by axcallet         ###   ########.fr       */
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
		data->input = add_spaces_rdir(data->input);
		data->input = remove_spaces_pipes(data->input);
		if (check_syntax(data->input))
		{
			printf("Syntax error\n");
			return (1);
		}
	//	DB_print_tab(turbo_split(data->input, '|'));
	//	DB_print_tab(input_to_tab(data->input));
		data = dtt_init(data);
		data = dtt_refile(data);
		DB_print_dtt(data);
		free(data->input);
	}
	return (0);
}
