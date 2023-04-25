/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:19:37 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/25 12:30:47 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"
#include "libft/libft.h"

static void	is_in_quote(int *c_quote, char c)
{
	if (c == '\'' && c_quote[1] == 0)
		c_quote[0] = 1;
	if (c == '\"' && c_quote[0] == 0)
		c_quote[1] = 1;
	if (c == '\'' && c_quote[0] == 1)
		c_quote = 0;
	if (c == '\"' && c_quote[1] == 1)
		c_quote = 0;
	return ;
}

static char	*get_variable(t_data *data, int index)
{
	int		i;
	int		j;
	char	*var;
	char	*tmp;

	i = 1;
	j = 0;
	while (data->input[index + i])
	{
		if (data->input[index + i] && is_separator(data->input[index + i]))
		{
			var = ft_substr(data->input, index + 1, i - 1);
			while (data->envp[j])
			{
				tmp = ft_strnstr(data->envp[j], var, i);
				if (tmp != NULL)
					return (ft_substr(data->envp[j], i,
							ft_strlen(data->envp[j]) - i));
				j++;
			}
		}
		i++;
	}
	return (NULL);
}

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

static int	ft_strlen_separator(char *str, int i)
{
	i++;
	while (!is_separator(str[i]))
		i++;
	return (i);
}

char	*input_mod_var(t_data *data)
{
	int		i;
	int		j;
	int		q_flag[2];
	char	*new_input;

	q_flag[0] = 0;
	q_flag[1] = 0;
	i = 0;
	j = 0;
	new_input = NULL;
	while (data->input[i])
	{
		is_in_quote(q_flag, data->input[i]);
		if (data->input[i] == '$' && q_flag[1] == 1)
		{
			new_input = add_variable(data,
					ft_substr(data->input, j, i - j), new_input);
			i += ft_strlen_separator(data->input, i);
			/*
			i++;
			while (!is_separator(data->input[i]))
				i++;
			*/
			j = i;
		}
		if (data->input[i + 1] == '\0')
			new_input = ft_secur_cat(new_input, ft_substr(data->input, j, i));
		i++;
	}
	return (new_input);
}
