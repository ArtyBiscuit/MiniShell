/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:38:42 by arforgea          #+#    #+#             */
/*   Updated: 2023/01/25 03:08:30 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	**split_cmd_flags(char *all_cmd)
{
	char	**cmd_and_flags;

	if (!all_cmd)
		return (NULL);
	cmd_and_flags = ft_split(all_cmd, ' ');
	if (!cmd_and_flags)
		return (NULL);
	return (cmd_and_flags);
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc < 5)
	{
		ft_perror("Error: ", NULL, "Bad_input...");
		return (2);
	}
	exec_pipeline(argc, argv, envp);
	return (0);
}
