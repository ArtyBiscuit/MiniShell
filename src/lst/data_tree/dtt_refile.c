/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtt_refile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:56:54 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/21 18:42:02 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../inc/minishell.h"

t_data	*dtt_refile(t_data *data)
{
	int		i;
	char	**tab;
	t_exec	*dtt_tmp;
	t_exec	*tmp;

	i = 0;
	dtt_tmp = data->dtt;
	tab = turbo_split(data->input, '|');
	//tab = input_to_tab(data->input);
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
	data->dtt = dtt_tmp;
	free_tab(tab);
	return (data);
}
