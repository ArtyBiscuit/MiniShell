/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:19:37 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/24 22:30:59 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"
#include <string.h>
static void    is_in_quote(int *c_quote, char c)
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
				{
					index = (ft_strlen(data->envp[j]) - i);
					return (ft_substr(data->envp[j], i, index));
				}
				j++;
			}
		}
		i++;
	}
	return (NULL);
}

static char	*add_variable(t_data *data, char *tmp)
{
	int		i;
	char	*new_str;

	i = 0;
	while (data->input[i])
	{
		if (data->input[i] && data->input[i] == '$')
			new_str = ft_secur_cat(tmp, get_variable(data, i));
		i++;
	}
	return (new_str);
}

char	*input_mod_var(t_data *data)
{
	int		i;
	int		j;
	int		q_flag[2];
	char 	*new_input;

	q_flag[0] = 0;
	q_flag[1] = 0;
	i = 0;
	j = 0;
	new_input = NULL;
	while (data->input[i])
	{
		is_in_quote(q_flag, data->input[i]);
		if ((data->input[i] == '$' || data->input[i] == '\0') && q_flag[1] == 1)
		{
			new_input = ft_substr(data->input, j, i);
			new_input = add_variable(data, new_input);
			i++;
			while (!is_separator(data->input[i]))
				i++;
		}
		/*
		if (new_input)
		{
			free(data->input);
			data->input = new_input;
		}
		*/

		i++;
	}
	
	return (new_input);
}
