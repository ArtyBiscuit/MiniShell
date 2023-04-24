/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refile_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:02:37 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/24 12:54:28 by arforgea         ###   ########.fr       */
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
			new_tab[j++] = ft_strdup(tab_cmd[i++]);
	}
	new_tab[j] = NULL;
	tmp->full_cmd = new_tab;
	tmp->cmd = new_tab[0];
	tmp->abs_path = get_abs_path(new_tab[0], envp);
	free_tab(tab_cmd);
	return (tmp);
}

static t_exec	*right_chevrons(t_exec *exec, char *cmd)
{
	int		i;
	int		out;
	char	*file;
	t_exec	*tmp;

	i = 0;
	tmp = exec;
	out = tmp->fd_out;
	if (out > 2)
		close (out);
	if (cmd[i] && cmd[i + 1] == '>')
	{
		file = get_next_word(&cmd[i]);
		out = open(file, O_CREAT | O_WRONLY | 0644);
		free(file);
	}
	else
	{
		file = get_next_word(&cmd[i]);
		out = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		free(file);
	}
	return (tmp);
}

static t_exec	*change_fds(t_exec *exec, char *cmd)
{
	int		i;
	int		in;
	char	*file;
	t_exec	*tmp;

	i = 0;
	tmp = exec;
	in = tmp->fd_in;
	while (cmd[i])
	{
		if (cmd[i] && cmd[i] == '<')
		{
			if (in > 2)
				close (in);
			file = get_next_word(&cmd[i]);
			in = open(file, O_RDONLY);
			free(file);
		}
		else if (cmd[i] && cmd[i] == '>')
			tmp = right_chevrons(tmp, cmd);
		i++;
	}
	return (tmp);
}

t_exec	*refile_exec(t_data *data, t_exec *dtt, char *cmd)
{
	// ta mere la pute! c'est pas "data->dtt" c'est le "tmp" ! pas DATA->DTT !!!!!!
	t_exec	*tmp;

	tmp = dtt;
	tmp->fd_in = 0;
	tmp->fd_out = 1;
	if (check_chevrons(cmd) == 1)
		tmp = change_fds(tmp, cmd);
	tmp = get_cmd(tmp, cmd, data->envp);
	return (tmp);
}
