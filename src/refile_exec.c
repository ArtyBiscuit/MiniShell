/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refile_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:02:37 by axcallet          #+#    #+#             */
/*   Updated: 2023/05/24 11:47:42 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

static int	get_good_nb_word(char **tab_cmd)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (tab_cmd[i])
	{
		if (tab_cmd[i][0] == '<' || tab_cmd[i][0] == '>')
			i += 2;
		else
		{
			i++;
			res++;
		}
	}
	return (res);
}

static t_exec	*get_cmd(t_exec *exec, char *cmd, char **envp)
{
	int		i;
	int		j;
	char	**new_tab;
	char	**tab_cmd;
	t_exec	*tmp;

	i = 0;
	j = 0;
	tab_cmd = turbo_split(cmd, ' ');
	tmp = exec;
	new_tab = malloc(sizeof(char *) * (get_good_nb_word(tab_cmd) + 1));
	while (tab_cmd[i])
	{
		if (tab_cmd[i][0] == '<' || tab_cmd[i][0] == '>')
			i += 2;
		else
		{
			new_tab[j] = ft_strdup(tab_cmd[i]);
			j++;
			i++;
		}
	}
	new_tab[j] = NULL;
	tmp->full_cmd = ft_tab_dup(new_tab);
	tmp->cmd = ft_strdup(new_tab[0]);
	tmp->abs_path = get_abs_path(new_tab[0], envp);
	free_tab(tab_cmd);
	free_tab(new_tab);
	return (tmp);
}

static t_exec	*change_fds(t_data *data, t_exec *dtt, char **tab, char *cmd)
{
	int		i;
	t_exec	*tmp;

	i = 0;
	tmp = dtt;
	while (cmd[i])
	{
		if (cmd[i] && cmd[i] == '<')
		{
			tmp = left_chevrons(data, tmp, tab, &cmd[i]);
			if (tmp->fd_in == -1)
				return (tmp);
			if (cmd[i] && cmd[i + 1] == '<')
				i++;
		}
		else if (cmd[i] && cmd[i] == '>')
		{
			tmp = right_chevrons(tmp, &cmd[i]);
			if (cmd[i] && cmd[i + 1] == '>')
				i++;
		}
		i++;
	}
	return (tmp);
}

t_exec	*refile_exec(t_data *data, t_exec *dtt, char **tab, char *cmd)
{	
	t_exec	*tmp;

	tmp = dtt;
	tmp->fd_in = 0;
	tmp->fd_out = 1;
	tmp->abs_path = NULL;
	tmp->cmd = NULL;
	tmp->full_cmd = NULL;
	if (check_chevrons(cmd) == 1)
		tmp = change_fds(data, tmp, tab, cmd);
	tmp = get_cmd(tmp, cmd, data->envp);
	return (tmp);
}
