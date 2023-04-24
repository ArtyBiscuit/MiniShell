/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtt_refile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:56:54 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/24 12:25:10 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../inc/minishell.h"

t_data	*dtt_refile(t_data *data)
{
	int		i;
	char	**tab;
	t_exec	*tmp;

	i = 0;
	//tab = turbo_split(data->input, '|');
	tab = input_to_tab(data->input);
	tmp = data->dtt;
	while (tab[i])
	{
		tmp = refile_exec(data, tmp, tab[i]);
		if (!tmp)
		{
			free_tab(tab);
			write(2, "Error: dtt_refile.", 18);
			return (NULL);
		}
		tmp = tmp->next;
		i++;
	}
	free_tab(tab);
	return (data);
}
