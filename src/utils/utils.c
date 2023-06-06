/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:53:43 by axcallet          #+#    #+#             */
/*   Updated: 2023/06/06 13:18:50 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/minishell.h"

int	is_separator(char c)
{
	return (is_space(c) || c == '|' || c == '\''
		|| c == '\"' || c == '\0');
}

int	strlen_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	return (i);
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char	*get_next_word(char *str)
{
	int		i;
	int		j;
	int		len_word;
	char	*next_word;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && (str[i] != ' ' && str[i] != '\t'))
			i++;
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i])
		{
			len_word = strlen_word(&str[i]);
			next_word = malloc(sizeof(char) * (len_word + 1));
			while (j <= len_word)
				next_word[j++] = str[i++];
			next_word[j - 1] = '\0';
			return (next_word);
		}
	}
	return (NULL);
}
