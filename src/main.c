/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:30:39 by axcallet          #+#    #+#             */
/*   Updated: 2023/03/15 15:49:17 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"
int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
	char	*str;

	while (1)
	{
		str = readline(">");
		if (str)
			printf("%s\n", str);
		else
			exit(1);
	}
//	printf("%s\n", get_abs_path(argv[1], envp));
//	echo("Lorem Ipsum", "n");
	return (0);
}
