/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:48:51 by axcallet          #+#    #+#             */
/*   Updated: 2023/05/24 17:14:08 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"
#include <stdlib.h>

static t_exec	*write_heredoc(t_data *data, t_exec *dtt, char **tab, char *word)
{
	char 	*new_input;
	t_exec	*tmp;

	tmp = dtt;
	signals_heredoc();
	new_input = readline("> ");
	while (new_input && ft_strncmp(new_input, word, ft_strlen(word) + 1))
	{
		ft_putstr_fd(new_input, tmp->fd_in);
		ft_putstr_fd("\n", tmp->fd_in);
		free(new_input);
		new_input = readline("> ");
	}
	if (!new_input && g_status != 3)
	{
		ft_putstr_fd("warning: here-document ", 2);
		ft_putstr_fd("delimited by end-of-file\n", 2);
	}
	else
		free(new_input);
	close(tmp->fd_in);
	free(word);
	lst_destroy(dtt);
	free_tab(tab);
	if (data->input)
		free(data->input);
	if (data->envp)
		free_tab(data->envp);
	if (data)
		free(data);
	printf("%d\n", g_status);
	if (g_status == 3)
		exit (130);
	exit(0);
}

t_exec	*heredoc(t_data *data, t_exec *dtt, char **tab, char *cmd)
{
	int		i;
	int		status;
	char	*word;
	pid_t	pid;
	t_exec	*tmp;

	i = 0;
	status = 0;
	tmp = dtt;
	tmp->fd_in = open("/tmp/.heredocc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (!tmp->fd_in)
		return (NULL);
	word = ft_strdup(cmd);
	printf("---\n%s\n---\n", word);
	signals_disabled();
	pid = fork();
	if (!pid)
		tmp = write_heredoc(data, tmp, tab, word);
	waitpid(pid, &status, 0);
	g_status = WEXITSTATUS(status);
	close(tmp->fd_in);
	if (g_status != 130)
		tmp->fd_in = open("/tmp/.heredocc", O_RDONLY, 0644);
	else
		tmp->fd_in = -1;
	free(word);
	return (tmp);
}

