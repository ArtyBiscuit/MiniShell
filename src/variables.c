/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:19:37 by axcallet          #+#    #+#             */
/*   Updated: 2023/05/18 11:58:48 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"
#include "libft/libft.h"
#include <unistd.h>
/*
static void	is_in_quote(int *c_quote, char c)
{
	if (c == '\'' && c_quote[1] == 0)
		c_quote[0] = 1;
	else if (c == '\"' && c_quote[0] == 0)
		c_quote[1] = 1;
	else if (c == '\'' && c_quote[0] == 1)
		c_quote[0] = 0;
	else if (c == '\"' && c_quote[1] == 1)
		c_quote[1] = 0;
	return ;
}
*/
static char	*get_variable(t_data *data, int index)
{
	int		i;
	int		j;
	char	*var;
	char	*tmp;

	i = 0;
	j = 0;
	while (data->input[index + i++])
	{
		if (data->input[index + i] && is_separator(data->input[index + i + 1]))
		{
			var = ft_substr(data->input, index + 1, i);
			if (var[0] == '?')
				return (ft_itoa(g_status));
			while (data->envp[j])
			{
				tmp = ft_strnstr(data->envp[j], var, i);
				if (tmp != NULL)
					return (ft_substr(data->envp[j], i + 1,
							ft_strlen(data->envp[j]) - i));
				j++;
			}
			if (data->envp[j] == NULL)
				return (var);
		}
	}
	return (NULL);
}
/*
static char	*add_variable(t_data *data, char *tmp, char *new_input)
{
	int		i;
	char	*new_str;

	i = 0;
	while (data->input[i])
	{
		if (data->input[i] && data->input[i] == '$')
		{
			new_str = ft_secur_cat(new_input, tmp);
			new_str = ft_secur_cat(new_str, get_variable(data, i));
		}
		i++;
	}
	return (new_str);
}

static void	change_variables(t_data *data, char **new, int *i, int *j)
{
	*new = add_variable(data,
			ft_substr(data->input, (*j), (*i) - (*j)), *new);
	(*i)++;
	while (!is_separator(data->input[*i]))
		(*i)++;
	(*j) = (*i);
}
*/

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

static void	change_variables(t_data *data, char **new, int *i, int *j)\
{
	*new = ft_substr(data->input, (*j), ((*i) - (*j)));
	*new = ft_strjoin(*new, get_variable(data, (*i)));
	i++;
	while (!is_separator(data->input[*i]))
		(*i)++;
	(*j) = (*i);
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
		else if (data->input[i] == '$')
			change_variables(data, &new, &i, &j);
		if (data->input[i + 1] == '\0')
			new = ft_strjoin(new, ft_substr(data->input, j, (i - j) + 1));
		i++;
	}
	if (data->input)
		free(data->input);
	return (new);
}

/*
char	*replace_variables(t_data *data)
{
	int		i;
	int		j;
	int		q_flag[2];
	char	*new;

	i = -1;
	j = 0;
	q_flag[0] = 0;
	q_flag[1] = 0;
	new = NULL;
	while (data->input && data->input[++i])
	{
		is_in_quote(q_flag, data->input[i]);
		if (i > 1 && data->input[i - 2] && data->input[i] == '$'
			&& (data->input[i - 1] == '<' && data->input[i - 2] == '<'))
			i++;
		if (data->input[i] == '$' && (q_flag[1] == 1
				|| (q_flag[0] == 0 && q_flag[1] == 0)))
		{
			change_variables(data, &new, &i, &j);
		}
		if (data->input[i + 1] == '\0')
			new = ft_secur_cat(new, ft_substr(data->input, j, i + 1));
	}
	free(data->input);
	return (new);
}
*/
