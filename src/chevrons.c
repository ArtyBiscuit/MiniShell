/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chevrons.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:35:54 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/11 10:57:22 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

int	check_chevrons(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] && (str[i] == '>' || str[i] == '<'))
			return (1);
		i++;
	}
	return (0);
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
			{
				next_word[j] = str[i];
				j++;
				i++;
			}
			next_word[j] = '\0';
			return (next_word);
		}
	}
	return (NULL);
}
