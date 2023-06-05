/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chevrons.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:35:54 by axcallet          #+#    #+#             */
/*   Updated: 2023/06/05 15:43:26 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"
#include "libft/libft.h"

char	*get_file(char *str)
{
	int		i;
	int		j;
	int		count;
	char	*res;

	i = 0;
	count = 0;
	while (str[i] && (str[i] == '<' || str[i] == '>') && count < 2)
	{
		i++;
		count++;
	}
	if (str[i] && str[i] == ' ')
		i++;
	j = i;
	while (is_rdir(str[i]))
		i++;
	while (!is_separator(str[i]))
		i++;
	res = ft_substr(str, j, (i - j));
	return (res);
}

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
	file = get_file(&cmd[i]);
	if (cmd[i + 1] == '<')
	{
		free(file);
		return (tmp);
	}
	else
	{
		tmp->fd_in = open(file, O_RDONLY);
		if (tmp->fd_in == -1)
		{
			printf("minishell: %s: No such file or directory\n", file);
			g_status = 1;
		}
	}
	free(file);
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
	file = get_file(&cmd[i]);
	if (cmd[i] && cmd[i + 1] == '>')
		tmp->fd_out = open(file, O_CREAT | O_WRONLY, 0644);
	else
		tmp->fd_out = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	free(file);
	return (tmp);
}
