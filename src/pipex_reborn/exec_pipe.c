/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:28:36 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/17 15:43:12 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include <stdlib.h>
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

void	exec_cmd(char *envp[], char *cmd, int fd_in, int *fd_out)
{
	char	**lst_path;
	char	**cmd_flags;
	char	*path_bin;
	pid_t	pid;

	lst_path = get_path_var(envp);
	cmd_flags = split_cmd_flags(cmd);
	path_bin = get_good_path(cmd_flags[0], lst_path);
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
		free_pipe_utils(lst_path, cmd_flags, path_bin);
		exit(0);
	}
	free_pipe_utils(lst_path, cmd_flags, path_bin);
}

int	exec_pipeline(int argc, char *argv[], char *envp[])
{
	int	fds[2];
	int	index;
	int	fd_tmp;

	fd_tmp = open_file(argv[1], 0);
	index = 2;
	while (index < argc - 2)
	{
		if (pipe(fds) < 0)
			return (1);
		exec_cmd(envp, argv[index], fd_tmp, fds);
		wait(NULL);
		close(fds[1]);
		close(fd_tmp);
		fd_tmp = fds[0];
		//close(fds[0]);
		index++;
	}
	fds[1] = open_file(argv[argc - 1], 1);
	fds[0] = -1;
	exec_cmd(envp, argv[index], fd_tmp, fds);
	close(fd_tmp);
	close(fds[1]);
	return (0);
}
