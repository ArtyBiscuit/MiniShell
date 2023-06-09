/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:56:28 by axcallet          #+#    #+#             */
/*   Updated: 2023/06/09 14:21:24 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_exec(char *str)
{
	int	i;

	i = 0;
	if (str && !ft_strncmp(str, "./", 2))
	{
		if (open(str, O_RDONLY) == -1)
		{
			perror(str);
			if (access(str, F_OK) == -1)
				g_status = 127;
			else
				g_status = 126;
			return (1);
		}
		if (open(str, O_DIRECTORY) != -1)
		{
			printf("minishell: %s: Is a directory\n", str);
			g_status = 126;
			return (1);
		}
	}
	return (0);
}

void	free_fork(t_data *data)
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

void	wait_all_pid(t_data *data, int *tab_pid)
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
