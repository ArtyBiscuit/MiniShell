/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:30:39 by axcallet          #+#    #+#             */
/*   Updated: 2023/06/03 17:03:14 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"
#include <stdlib.h>
#include <unistd.h>

int	g_status;

static void	minishell_process(t_data *data)
{
	data->input = readline("MiniShell $: ");
	if (!data->input)
		data->input = ft_strdup("exit");
	if (data->input)
	{
		add_history(data->input);
		if (check_syntax(data->input))
		{
			printf("Syntax error\n");
			g_status = 2;
			free(data->input);
			return ;
		}
		input_restructure(data);
			if (!data->input)
				return ;
		data = dtt_init(data);
		data = dtt_refile(data);
		exec_pipeline(data);
		lst_destroy(data->dtt);
		if (data->input)
			free(data->input);
	}
	return ;
}

char	**ft_tab_dup(char **tab)
{
	int		i;
	char	**new;

	i = 0;
	new = malloc(sizeof(char *) * (get_env_size(tab) + 1));
	if (!new)
	{
		free(new);
		return (NULL);
	}
	while (tab[i])
	{
		new[i] = ft_strdup(tab[i]);
		if (!new[i])
		{
			free_tab(new);
			return (NULL);
		}
		i++;
	}
	new[i] = NULL;
	return (new);
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
	while (1)
	{
		minishell_process(data);
	}
	return (0);
}
