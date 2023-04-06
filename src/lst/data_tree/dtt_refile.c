/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtt_refile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:56:54 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/06 18:02:26 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../inc/minishell.h"

t_data	*dtt_refile(t_data *data)
{
	int		i;
	char	**tab;
	t_exec	*tmp;
	
	i = 0;
	tab = split_pipes(data->input);
	tmp = data->dtt;
	while (tab[i])
	{
		if (check_chevrons(tab[i]))
		{
			tmp->rdir = get_chevron(tmp->rdir, tab[i]);
			if (!tmp->rdir)
				return (NULL);
		}
//		else
//		{
//			tmp->cmd = get_cmd(tmp->cmd, tab[i]);
//			if (!tmp->rdir)
//				return (NULL);
//		}
		tmp = tmp->next;
		i++;
	}
//	free_tab(tab);	
	return (data);
}
