/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:30:39 by axcallet          #+#    #+#             */
/*   Updated: 2023/03/17 13:44:41 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

int main(int argc, char **argv, char **envp)
{
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
			parsing(input, data);
		free(input);
	}
	return (0);
}
