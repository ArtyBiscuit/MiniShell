/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chevrons.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:35:54 by axcallet          #+#    #+#             */
/*   Updated: 2023/05/03 10:00:03 by axcallet         ###   ########.fr       */
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

static t_exec	*ft_heredoc(t_exec *dtt, char *cmd)
{
	int		i;
	char	*word;
	char	*new_input;
	t_exec	*tmp;

	i = 0;
	tmp = dtt;
	tmp->fd_in = open("/tmp/.heredocc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	word = get_next_word(&cmd[i]);
	new_input = readline("> ");
	while (ft_strncmp(new_input, word, ft_strlen(word)) != 0)
	{
		free(new_input);
		new_input = readline("> ");
		if (!new_input)
		{
			return (NULL);
		}
		ft_putstr_fd(ft_strjoin(new_input, "\n"), tmp->fd_in);
	}
	close(tmp->fd_in);
	tmp->fd_in = open("/tmp/.heredocc", O_RDONLY, 0644);
	return (tmp);
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
		tmp = ft_heredoc(tmp, &cmd[i]);
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

