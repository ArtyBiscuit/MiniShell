/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:30:39 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/17 13:31:05 by axcallet         ###   ########.fr       */
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
			printf("Syntax error\n");
		data = dtt_init(data);
		data = dtt_refile(data);
		//free(data->input);
	}
	return (0);
}
