/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:28:36 by arforgea          #+#    #+#             */
/*   Updated: 2023/06/05 17:49:11 by axcallet         ###   ########.fr       */
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

static void	free_fork(t_data *data)
{
	if (data->input)
		free(data->input);
	if (data->tab_pid)
		free(data->tab_pid);
	if (data->envp)
		free_tab(data->envp);
	lst_destroy(data->dtt);
	if (data)
		free(data);
}

static int	fork_exec(t_data *data, t_exec *dtt, int *fds, int fd_in)
{
	pid_t	pid;

	signal_exec();
	pid = fork();
	if (pid < 0)
		perror("fork");
	if (!pid)
	{
		if (!dtt->abs_path && dtt->cmd)
		{
			printf("Command '%s' not found\n", dtt->cmd);
			free_fork(data);
			exit (127);
		}
		all_dup2(dtt, fds, fd_in);
		if (!check_after_fork(data, dtt) && dtt->cmd)
		{
			g_status = 0;
			execve(dtt->abs_path, dtt->full_cmd, data->envp);
		}
		free_fork(data);
		exit (g_status);
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

static int	check_exec(char *str)
{
	int		i;
	char	*exec;

	i = 0;
	if (str && ft_strlen(str) > 2)
	{
		exec = ft_substr(str, 2, strlen_word(&str[2]));
		if (open(exec, O_DIRECTORY) != -1)
		{
			printf("minishell: %s: Is a directory\n", str);
			g_status = 126;
			free(exec);
			return (1);
		}
		free(exec);
	}
	return (0);
}

void	exec_core(t_data *data, t_exec *ptr, int *fd_in, int i)
{
	if (!ft_strncmp(ptr->cmd, "exit", 4))
		ft_exit(data, data->dtt);
	else if (check_exec(ptr->cmd))
		data->tab_pid[i] = 0;
	else if (!check_before_fork(data, ptr) && ptr->fd_in != -1)
	{	
		*fd_in = ft_pipe(data, ptr, &data->tab_pid[i], *fd_in);
		if (g_status != 130)
		g_status = 0;
	}
	else
		data->tab_pid[i] = 0;
}

int	exec_pipeline(t_data *data)
{
	int		i;
	int		fd_in;
	t_exec	*ptr;

	i = 0;
	ptr = data->dtt;
	fd_in = ptr->fd_in;
	data->tab_pid = malloc(sizeof(pid_t) * data->nb_cmd);
	while (ptr)
	{
		exec_core(data, ptr, &fd_in, i);
		ptr = ptr->next;
		i++;
	}
	wait_all_pid(data, data->tab_pid);
	if (fd_in > 0)
		close(fd_in);
	free(data->tab_pid);
	return (0);
}
