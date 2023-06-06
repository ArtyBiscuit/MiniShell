/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refile_exec_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:44:03 by axcallet          #+#    #+#             */
/*   Updated: 2023/06/06 13:09:20 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../inc/minishell.h"

int	check_heredoc(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] && is_rdir(str[i]) && is_rdir(str[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	get_good_nb_word(char **tab_cmd)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (tab_cmd[i])
	{
		if (tab_cmd[i + 1] && (tab_cmd[i][0] == '<' || tab_cmd[i][0] == '>'))
			i += 2;
		else
		{
			i++;
			res++;
		}
	}
	return (res);
}
