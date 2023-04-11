/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refile_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:02:37 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/11 11:13:38 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"
/*
static char	*str_without_chevrons(char *cmd)
{
	int		i;
	char	*res;
	char	**tab_cmd;

	i = 0;
	res = NULL;
	tab_cmd = ft_split(cmd, ' ');
	while (tab_cmd[i])
	{
		if (check_chevrons(tab_cmd[i]) == 1)
			i += 2;
		else
		{
			res = ft_strjoin(res, tab_cmd[i]);
			i++;
		}
	}
	return (res);
}

static t_exec	*get_cmd(t_exec *exec, char *cmd)
{
	int		i;
	char	*buf;
	t_exec	*tmp;

	i = 0;
	buf = str_without_chevrons(cmd);
	tmp = exec;
		
}
*/
static t_exec	*right_chevrons(t_exec *exec , char *cmd)
{
	int		i;
	int		out;
	char	*file;
	t_exec	*tmp;

	i = 0;
	tmp = exec;
	out	= tmp->fd_out;
	close (out);
	if (cmd[i] && cmd[i + 1] == '>')
	{
		file = get_next_word(&cmd[i]);
		out	= open(file, O_CREAT | O_WRONLY | 0644);
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

t_exec	*refile_exec(t_exec *exec, char *cmd)
{
	t_exec	*tmp;

	tmp = exec;
	tmp->fd_in = 0;
	tmp->fd_out = 1;
	if (check_chevrons(cmd) == 1)
		tmp = change_fds(tmp, cmd);
//	tmp = get_cmd(tmp, cmd);
	return (tmp);
}
