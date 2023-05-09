/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:30:39 by axcallet          #+#    #+#             */
/*   Updated: 2023/05/09 13:08:49 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

int	g_status;

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	t_data	*data;	

	data = malloc(sizeof(t_data));
	data->envp = envp;
	g_status = 0;
	signal(SIGINT, mini_sigint);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		data->input = readline("MiniShell $: ");
		if (!data->input)
			data->input = ft_strdup("exit");
		if (data->input)
		{
			add_history(data->input);
			if (!ft_strncmp(data->input, "exit", 5))
				exit(0);
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
	}
	if (data)
		free(data);
	return (0);
}
