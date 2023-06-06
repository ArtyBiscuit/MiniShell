/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:56:28 by axcallet          #+#    #+#             */
/*   Updated: 2023/06/06 11:42:49 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minishell.h"

int	check_exec(char *str)
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
