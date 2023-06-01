/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:05:00 by arforgea          #+#    #+#             */
/*   Updated: 2023/06/01 17:44:40 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minishell.h"
#include <stdio.h>
#include <stdlib.h>

static char	*get_format_var(char *var)
{
	char	*new_var;
	int		i;
	int		j;
	
	new_var = malloc(sizeof(char) * get_var_size(var) + 1);
	i = 0;
	j = 0;
	while (var[i])
	{
		if (var[i] == '\'' || var[i] == '"')
		{
			i++;
			continue ;
		}
		new_var[j] = var[i];
		j++;
		i++;
	}
	new_var[j] = '\0';
	return (new_var);
}

static int	is_var(char **envp, char *var)
{
	int	i;
	int	var_size;

	i = 0;
	var_size = get_name_var_size(var);
	while (envp[i])
	{
		if (!ft_strncmp(var, envp[i], var_size))
			return (1);
		i++;
	}
	return (0);
}

static char	**add_var(char **envp,char *var)
{
	char	**new_envp;
	int		var_size;
	int		envp_size;
	int		i;

	envp_size = get_env_size(envp);
	var_size = get_name_var_size(var);
	if (is_var(envp, var))
		new_envp = malloc(sizeof(char *) * (envp_size + 1));
	else
		new_envp = malloc(sizeof(char *) * (envp_size + 2));
	i = 0;
	while(i < envp_size)
	{
		if (!ft_strncmp(var, envp[i], var_size))
			new_envp[i] = get_format_var(var);
		else
			new_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	if (is_var(envp, var))
		new_envp[i] = NULL;
	else
	{
		new_envp[i] = get_format_var(var);
		new_envp[i + 1] = NULL;
	}
	return (new_envp);
}

static int check(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (str[i] == '-')
		{
			printf("bash: `%c%c' invalid option\n", str[i], str[i+1]);
			g_status = 2;
			return (1);
		}
		i++;
	}
	if (!ft_isalpha(str[0]) && str[0] != '_')
	{
		printf("bash: export: `%s': not a valid identifier\n", str);
		g_status = 1;
		return (1);
	}
	return (0);
}

int	ft_export(char ***envp, char **tab_cmd)
{
	int		index;
	char	**new_envp;

	index = 1;
	if (!tab_cmd[1])
	{
		print_tab_sort(*envp);
		return (0);
	}
	while (tab_cmd[index])
	{
		if (!check(tab_cmd[index]))
		{
			new_envp = add_var(*envp, tab_cmd[index]);
			free_tab(*envp);
			*envp = new_envp;
		}
		index++;
	}
	return (0);
}
