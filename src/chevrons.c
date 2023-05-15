/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chevrons.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:35:54 by axcallet          #+#    #+#             */
/*   Updated: 2023/05/10 15:21:33 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

int	check_chevrons(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] && (str[i] == '>' || str[i] == '<'))
			return (1);
		i++;
	}
	return (0);
}

int	is_rdir(char c)
{
	return (c == '<' || c == '>');
}

t_exec	*left_chevrons(t_exec *dtt, char *cmd)
{
	int		i;
	char	*file;
	t_exec	*tmp;

	i = 0;
	tmp = dtt;
	if (tmp->fd_in > 2)
		close(tmp->fd_in);
	if (cmd[i + 1] == '<')
		tmp = heredoc(tmp, &cmd[i]);
	else
	{
		file = get_next_word(&cmd[i]);
		tmp->fd_in = open(file, O_RDONLY);
		free(file);
	}
	return (tmp);
}

t_exec	*right_chevrons(t_exec *dtt, char *cmd)
{
	int		i;
	char	*file;
	t_exec	*tmp;

	i = 0;
	tmp = dtt;
	if (tmp->fd_out > 2)
		close (tmp->fd_out);
	if (cmd[i] && cmd[i + 1] == '>')
	{
		file = get_next_word(&cmd[i]);
		tmp->fd_out = open(file, O_CREAT | O_WRONLY, 0644);
		free(file);
	}
	else
	{
		file = get_next_word(&cmd[i]);
		tmp->fd_out = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		free(file);
	}
	return (tmp);
}
