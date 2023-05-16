/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:28:36 by arforgea          #+#    #+#             */
/*   Updated: 2023/05/16 17:27:14 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

static void	all_dup2(t_exec *dtt, int *fds, int fd_in)
{
	if (dtt->fd_in > 2)
	{
		dup2(dtt->fd_in, 0);
		close(dtt->fd_in);
	}
	else if (dtt->back)
	{
		dup2(fd_in, 0);
		if (fd_in != -1)
			close(fd_in);
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

static void	wait_all_pid(t_data *data, int *tab_pid)
{
	int	i;
	int	status;

	i = 0;
	while (i != data->nb_cmd)
	{
		if (tab_pid[i] != 0)
			waitpid(tab_pid[i], &status, 0);
		if (g_status == 131)
			ft_putstr_fd("Quit core dumped\n", 2);
		if (tab_pid[i] && WIFEXITED(status))
			g_status = WEXITSTATUS(status);
		i++;
	}
	signal(SIGINT, mini_sigint);
}

static int	fork_exec(t_data *data, t_exec *dtt, int *fds, int fd_in)
{
	pid_t	pid;
	
	signal(SIGINT, SIG_IGN);
	pid = fork();
	signal(SIGINT, mini_sigint_fork);
	signal(SIGQUIT, mini_sigquit_fork);
	if (pid < 0)
		perror("fork");
	if (!pid)
	{
		all_dup2(dtt, fds, fd_in);
		if (!check_after_fork(data, dtt))
			execve(dtt->abs_path, dtt->full_cmd, data->envp);
		lst_destroy(dtt);
		if (data->input)
			free(data->input);
		if (data->envp)
			free_tab(data->envp);
		if (data)
			free(data);
		exit (0);
	}
	return (pid);
}

static int	ft_pipe(t_data *data, t_exec *dtt, int *pid, int fd_in)
{
	int		fds[2];
	t_exec	*ptr;

	ptr = dtt;
	if (pipe(fds))
	{
		perror("pipe");
		return (1);
	}
	if (fd_in == -1)
		fd_in = fds[0];
	*pid = fork_exec(data, ptr, fds, fd_in);
	close(fds[1]);
	if (fd_in > 0)
		close(fd_in);
	return (fds[0]);

}

int	exec_pipeline(t_data *data)
{
	int		i;
	int		fd_in;
	int		tab_pid[data->nb_cmd];
	t_exec	*ptr;

	i = 0;
	ptr = data->dtt;
	fd_in = ptr->fd_in;
	while (ptr)
	{
		if (!ft_strncmp(ptr->cmd, "exit", 4))
			ft_exit(data, data->dtt);
		if (!check_before_fork(data, ptr))
			fd_in = ft_pipe(data, ptr, &tab_pid[i], fd_in);
		else
			tab_pid[i] = 0;
		ptr = ptr->next;
		i++;
	}
	wait_all_pid(data, tab_pid);
	if (fd_in > 0)
		close(fd_in);
	return (0);
}
