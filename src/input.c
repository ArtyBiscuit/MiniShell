/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:42:51 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/12 15:16:43 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

static int	my_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
			|| c == '\r' || c == '\f' || c == '\v')
    	return (1);
	return (0);
}

char	*input_restructuring(char* str)
{
	size_t	i;
	int		j;
    char	*result;

	i = 0;
	j = 0;
	result = malloc(sizeof(char) * (ft_strlen(str) * 2 + 1));
	while (i < ft_strlen(str))
	{
        if (str[i] == '>' || str[i] == '<' || str[i] == '|'
				|| str[i] == '&' || str[i] == ';')
		{
            if (i > 0 && !my_isspace(str[i - 1]))
                result[j++] = ' ';
            result[j] = str[i];
            if (i < (ft_strlen(str) - 1) && !my_isspace(str[i + 1]))
                result[++j] = ' ';
		}
		else
			result[j] = str[i];
		i++;
        j++;
    }
    result[j] = '\0'; 
    return (result);
}
