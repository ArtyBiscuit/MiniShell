/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:30:39 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/04 15:02:13 by arty             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_exec	*dtt;
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
		dtt = dtt_init(input);
		free(input);
	}
	return (0);
}
