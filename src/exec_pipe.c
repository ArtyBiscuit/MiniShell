/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:28:36 by arforgea          #+#    #+#             */
/*   Updated: 2023/05/03 08:53:32 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

static void	all_dup2(t_exec *dtt, int *fds, int fd_tmp)
{
	if (dtt->fd_in > 2)
	{
		dup2(dtt->fd_in, 0);
		close(dtt->fd_in);
	}
	else if (dtt->back)
	{
		dup2(fd_tmp, 0);
		if (fd_tmp != -1)
			close(fd_tmp);
	}
	if (dtt->fd_out > 2)
	{
		dup2(dtt->fd_out, 1);
		close (dtt->fd_out);
	}
	else if (dtt->next)
	{
		dup2(fds[1], 1);
		close(fds[1]);
		close(fds[0]);
	}
}

static int	exec_cmd(char *envp[], t_exec *dtt, int *fds, int fd_tmp)
{
	char	**tab_cmd;
	char	*path_bin;
	pid_t	pid;

	tab_cmd = dtt->full_cmd;
	path_bin = dtt->abs_path;
	pid = 1;
	if (tab_cmd && path_bin)
		pid = fork();
	else
		printf("walla ça marche pas !");
	if (!pid)
	{
		all_dup2(dtt, fds, fd_tmp);
		execve(path_bin, tab_cmd, envp);
		exit(0);
	}
	return (pid);
}

static void	close_fds_cmd(t_exec *dtt, int fd_tmp)
{
	if (dtt->fd_in > 2)
		close(dtt->fd_in);
	if (dtt->fd_out > 2)
		close(dtt->fd_out);
	if (dtt->back)
		close(fd_tmp);
}

static void	wait_all_pid(t_data *data, int *tab_pid)
{
	int	i;

	i = 0;
	while (i != data->nb_cmd)
	{
		waitpid(tab_pid[i], NULL, 0);
		i++;
	}
}

int	exec_pipeline(t_data *data)
{
	int		fds[2];
	int		fd_tmp;
	int		index;
	int		*tab_pid;
	t_exec	*tmp;

	tmp = data->dtt;
	index = 0;
	fd_tmp = -1;
	tab_pid = malloc(sizeof(int) * data->nb_cmd);
	while (tmp)
	{
		if (pipe(fds) < 0)
			return (1);
		tab_pid[index++] = exec_cmd(data->envp, tmp, fds, fd_tmp);
		close(fds[1]);
		close_fds_cmd(tmp, fd_tmp);
		fd_tmp = fds[0];
		tmp = tmp->next;
	}
	if (fd_tmp != -1)
		close(fd_tmp);
	wait_all_pid(data, tab_pid);
	return (0);
}
