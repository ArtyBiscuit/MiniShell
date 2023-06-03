/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:19:37 by axcallet          #+#    #+#             */
/*   Updated: 2023/06/03 18:57:44 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

int	char_is_valid(char c)
{
	int		i;
	char	*tab;

	i = 0;
	tab = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";
	while (tab[i])
	{
		if (tab[i] == c)
			return (0);
		i++;
	}
	return (1);
}

static char *final_variable(char *var, t_data *data, int j, int i)
{
	free(var);
	return (ft_substr(data->envp[j], i + 1,
	ft_strlen(data->envp[j]) - i));
}

static char	*get_variable(t_data *data, int index)
{
	int		i;
	int		j;
	char	*var;
	char	*tmp;

	i = -1;
	j = -1;
	if (data->input[index + 1] == '?')
		return (ft_itoa(g_status));
	while (data->input[index + ++i])
	{
		if (data->input[index + i] && char_is_valid(data->input[index + i + 1]))
		{
			var = ft_substr(data->input, index + 1, i);
			while (data->envp[++j])
			{
				tmp = ft_strnstr(data->envp[j], var, i);
				if (tmp != NULL)
					return (final_variable(var, data, j, i));
			}
			if (data->envp[j] == NULL)
				break ;
		}
	}
	free(var);
	return (NULL);
}

static int	check_flag(int flag, char c)
{
	if (c == '\'' && flag == 0)
		flag = 1;
	else if (c == '\'' && flag == 1)
		flag = 0;
	else if (c == '\"' && flag == 0)
		flag = 2;
	else if (c == '\"' && flag == 2)
		flag = 0;
	return (flag);
}

static void	change_variables(t_data *data, char **new, int *i, int *j)
{
	*new = ft_secur_cat(*new, ft_substr(data->input, (*j), ((*i) - (*j))));
	*new = ft_secur_cat(*new, get_variable(data, (*i)));
	(*i)++;
	if (!data->input[(*i) + 1])
		(*i)++;
	if (data->input[(*i)] == '?')
		(*i)++;
	else if (data->input[(*i)])
	{
		while (!is_separator(data->input[(*i)]) && data->input[*i] != '$')
			(*i)++;
	}
	(*j) = (*i);
}

static int	check_heredoc(char *str, int i)
{
	while (i != 0 || str[i] == '|')
	{
		if (str[i] == '<' && str[i - 1] == '<')
			return (1);
		i--;
	}
	return (0);
}

char	*replace_variables(t_data *data)
{
	int		i;
	int		j;
	int		flag;
	char	*new;

	i = 0;
	j = 0;
	flag = 0;
	new = NULL;
	while (data->input[i])
	{
		flag = check_flag(flag, data->input[i]);
		if (data->input[i] == '\'' && flag == 1)
			i += (skip_argument(&data->input[i]) - 1);
		else if (data->input[i] == '$' && !check_heredoc(data->input, i))
			change_variables(data, &new, &i, &j);
		if (data->input[i] == '\0' || data->input[i + 1] == '\0')
		{
			new = ft_secur_cat(new, ft_substr(data->input, j, (i - j) + 1));
			if (data->input)
				free(data->input);
			return (new);
		}
		else if (data->input[i] == '$' && !check_heredoc(data->input, i))
			continue ;
		i++;
	}
	if (data->input)
		free(data->input);
	return (new);
}
