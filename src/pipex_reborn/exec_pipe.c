/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:28:36 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/29 16:08:29 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include "../../inc/minishell.h"
#include <stdio.h>
#include <unistd.h>
/*
int	exec_cmd(char *envp[], t_exec *dtt, int *fds)
{
	char	**cmd_flags;
	char	*path_bin;
	pid_t	pid;

	cmd_flags = dtt->full_cmd;
	path_bin = dtt->abs_path;
	pid = 1;
	if (cmd_flags && path_bin)
		pid = fork();
	else
		ft_perror("command not found: ", cmd_flags, "Empty");
	if (pid == 0)
	{
		if (dtt->fd_in > 2)
		{
			dup2(dtt->fd_in, 0);
			close(dtt->fd_in);
		}
		else if (dtt->back)
		{
			dup2(fds[0], 0);
		}
		if (dtt->fd_out > 2)
		{
			dup2(dtt->fd_out, 1);
			close (dtt->fd_out);
		}
		else if (dtt->next)
		{
			dup2(fds[1], 1);
		}
		execve(path_bin, cmd_flags, envp);
		exit(0);
	}
	return (pid);
}

int	exec_pipeline(t_data *data)
{
	int	fds[2];
	t_exec	*dtt;
	int i;

	i = 0;
	dtt = data->dtt;
	while (dtt)
	{
		if (dtt->next && pipe(fds) < 0)
			return (1);
		exec_cmd(data->envp, dtt, fds);
		dtt = dtt->next;
		i++;
	}
	close (fds[0]);
	close (fds[1]);
	while (i-- > 0)
		waitpid(-1, NULL, 0);
	return (0);
}
*/
void	free_pipe_utils(char **tab_cmd, char *path_bin)
{
	int	index;

	index = 0;
	free(path_bin);
	while (tab_cmd[index])
	{
		free(tab_cmd[index]);
		index++;
	}
	free(tab_cmd);
}

int	exec_cmd(char *envp[], t_exec *dtt, int *fds, int fd_tmp)
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
		ft_perror("command not found: ", tab_cmd, "Empty");
	if (!pid)
	{
		if (dtt->fd_in > 2)
		{
			printf("0");
			dup2(dtt->fd_in, 0);
			close(dtt->fd_in);
		}
		else if (dtt->back)
		{
			printf("1");
			dup2(fd_tmp, 0);
			if (fd_tmp != -1)
				close(fd_tmp);
		}
		if (dtt->fd_out > 2)
		{
			printf("2");
			dup2(dtt->fd_out, 1);
			close (dtt->fd_out);
		}
		else if (dtt->next)
		{
			printf("3");
			dup2(fds[1], 1);
			close(fds[1]);
			close(fds[0]);
		}
		execve(path_bin, tab_cmd, envp);
		exit(0);
	}
	return (pid);
}

int	exec_pipeline(t_data *data)
{
	int		fds[2];
	int		fd_tmp;
	int		index;
	int		*tab_pid;
	t_exec	*tmp;

	index = 0;
	tmp = data->dtt;
	fd_tmp = -1;
	tab_pid = malloc(sizeof(int) * data->nb_cmd);
	while (tmp->next)
	{
		if (pipe(fds) < 0)
			return (1);
		tab_pid[index] = exec_cmd(data->envp, tmp, fds, fd_tmp);
		close(fds[1]);
		if (tmp->fd_in > 2)
			close(tmp->fd_in);
		if (tmp->fd_out > 2)
			close(tmp->fd_out);
		if (tmp->back)
			close(fd_tmp);
		fd_tmp = fds[0];
		tmp = tmp->next;
		index++;	
	}
	tab_pid[index] = exec_cmd(data->envp, tmp, fds, fd_tmp);
	if (fd_tmp != -1)
		close(fd_tmp);
	if (tmp->fd_in > 2)
		close(tmp->fd_in);
	if (tmp->fd_out > 2)
		close(tmp->fd_out);
	index = 0;
	while (index != data->nb_cmd)
		waitpid(tab_pid[index++], NULL, 0);
	return (0);
}
