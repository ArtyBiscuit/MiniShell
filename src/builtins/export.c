/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:05:00 by arforgea          #+#    #+#             */
/*   Updated: 2023/05/16 14:05:06 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minishell.h"

static char	*get_format_var(char *var)
{
	char	*new_var;
	int		i;
	int		j;
	
	new_var = malloc(sizeof(char) * get_var_size(var) + 2);
	i = 0;
	j = 0;
	while (var[i] != '=' && var[i])
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
	new_var[j] = '=';
	new_var[j + 1] = '\0';
	return (new_var);
}

static char	**add_var(char **envp,char *var)
{
	char	**new_envp;
	int		var_size;
	int		envp_size;
	int		i;

	var_size = get_var_size(var);
	envp_size = get_env_size(envp);
	new_envp = malloc(sizeof(char *) * (envp_size + 2));
	i = 0;
	while(i < envp_size)
	{
		new_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	new_envp[i] = get_format_var(var);
	new_envp[i + 1] = NULL;
	return (new_envp);
}

int	ft_export(char ***envp, char *str)
{
	char	**new_envp;

	if (!str)
	{
		print_tab_sort(*envp);
		return (0);
	}
	new_envp = add_var(*envp, str);
	*envp = new_envp;
	return (0);
}
