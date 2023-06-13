/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:30:39 by axcallet          #+#    #+#             */
/*   Updated: 2023/06/13 14:08:50 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	g_status;

static void	minishell_process(t_data *data)
{
	while (1)
	{
		data->input = readline("MiniShell $: ");
		if (!data->input)
			data->input = ft_strdup("exit");
		if (string_is_empty(data->input))
			add_history(data->input);
		if (check_syntax(data->input))
		{
			printf("Syntax error\n");
			g_status = 2;
			free(data->input);
			continue ;
		}
		input_restructure(data);
		if (!data->input)
			continue ;
		data = dtt_init(data);
		data = dtt_refile(data);
		// DB_print_dtt(data);
		exec_pipeline(data);
		if (data->input)
			free(data->input);
		lst_destroy(data->dtt);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	(void)argv;
	if (argc > 1)
	{
		ft_putstr_fd("Wrong number of arguments\n", 2);
		return (0);
	}
	data = malloc(sizeof(t_data));
	data->envp = ft_tab_dup(envp);
	g_status = 0;
	signal(SIGINT, mini_sigint);
	signal(SIGQUIT, SIG_IGN);
	minishell_process(data);
	return (0);
}
