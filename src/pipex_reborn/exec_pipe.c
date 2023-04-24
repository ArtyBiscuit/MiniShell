/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:28:36 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/24 12:58:40 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include "../../inc/minishell.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void	free_pipe_utils(char **lst_path, char **cmd_flags, char *path_bin)
{
	int	index;

	free(path_bin);
	index = 0;
	while (cmd_flags[index])
	{
		free(cmd_flags[index]);
		index++;
	}
	free(cmd_flags);
	index = 0;
	while (lst_path[index])
	{
		free(lst_path[index]);
		index++;
	}
	free(lst_path);
}

void	exec_cmd(char *envp[], t_exec *dtt, int fd_in, int *fd_out)
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
	if (!pid)
	{
		if (fd_out[0] != -1)
			close(fd_out[0]);
		dup2(fd_in, 0);
		dup2(fd_out[1], 1);
		execve(path_bin, cmd_flags, envp);
		exit(0);
	}
}

int	exec_pipeline(t_data *data)
{
	int	fds[2];
	int	fd_tmp;
	t_exec	*dtt;

	dtt = data->dtt;
	fd_tmp = dtt->fd_in;
	while (dtt->next)
	{
		if (pipe(fds) < 0)
			return (1);
		exec_cmd(data->envp, dtt, fd_tmp, fds);
		wait(NULL);
		close(fds[1]);
		fd_tmp = fds[0];
		dtt = dtt->next;
	}
	fds[1] = dtt->fd_out;
	fds[0] = -1;
	exec_cmd(data->envp, dtt, fd_tmp, fds);
	wait(NULL);
	close(fd_tmp);
	return (0);
}
