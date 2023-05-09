/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:48:51 by axcallet          #+#    #+#             */
/*   Updated: 2023/05/09 17:07:03 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

static t_exec	*write_heredoc(t_exec *dtt, char *word)
{
	char 	*new_input;
	t_exec	*tmp;

	tmp = dtt;
	signals_heredoc();
	new_input = readline("> ");
	while (new_input && ft_strncmp(new_input, word, ft_strlen(word) + 1))
	{
		ft_putstr_fd(ft_strjoin(new_input, "\n"), tmp->fd_in);
		free(new_input);
		new_input = readline("> ");
	}
	if (!new_input)
	{
		if (g_status == 3)
		{
			ft_putchar_fd('\n', 1);
			exit(0);
		}
		ft_putstr_fd("warning: here-document ", 2);
		ft_putstr_fd("delimited by end-of-file\n", 2);
	}
	else
		free(new_input);
	close(tmp->fd_in);
	return (tmp);
	//exit(0);
}

t_exec	*heredoc(t_exec *dtt, char *cmd)
{
	int		i;
	int		status;
	char	*word;
	pid_t	pid;
	t_exec	*tmp;

	i = 0;
	tmp = dtt;
	tmp->fd_in = open("/tmp/.heredocc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (!tmp->fd_in)
		return (NULL);
	word = get_next_word(&cmd[i]);
	signals_disabled();
	pid = fork();
	if (!pid)
		tmp = write_heredoc(tmp, word);
	waitpid(pid, &status, 0);
	if (WEXITSTATUS(status) == 3)
		exit(130);
	close(tmp->fd_in);
	tmp->fd_in = open("/tmp/.heredocc", O_RDONLY, 0644);
	return (tmp);
}

