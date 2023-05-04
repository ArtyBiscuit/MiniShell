/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:30:39 by axcallet          #+#    #+#             */
/*   Updated: 2023/05/03 10:09:36 by axcallet         ###   ########.fr       */
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
		while (1)
		{
			data->input = readline("MiniShell $: ");
			add_history(data->input);
			if (data->input[0] == '\0')
			{
				printf("%s", data->input);
				continue;
			}
			else
				break;
		}
		data->input = input_mod_var(data);
		data->input = remove_extra_spaces(data->input);
		data->input = add_spaces_rdir(data->input);	
		data->input = remove_spaces_pipes(data->input);
		if (check_syntax(data->input))
		{
			printf("Syntax error\n");
			continue;
		}
		data = dtt_init(data);
		data = dtt_refile(data);
	//	DB_print_dtt(data);
		exec_pipeline(data);
		lst_destroy(data->dtt);
		if (data->input)
			free(data->input);
	}
	if (data)
		free(data);
	return (0);
}
