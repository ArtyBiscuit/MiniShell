/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:53:43 by axcallet          #+#    #+#             */
/*   Updated: 2023/05/18 14:10:17 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

int	is_separator(char c)
{
	return (is_space(c) || c == '|' || c == '\''
		|| c == '\"' || c == '$' || c == '\0');
}

int	strlen_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	return (i);
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

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char	*ft_secur_cat(char *s1, char *s2)
{
	int		s_s1;
	int		s_s2;
	char	*f_str;

	s_s1 = 0;
	s_s2 = 0;
	if (s1)
		s_s1 = ft_strlen(s1);
	if (s2)
		s_s2 = ft_strlen(s2);
	f_str = malloc(sizeof(char) * (s_s1 + s_s2) + 1);
	if (s1)
	{
		ft_strlcpy(f_str, s1, s_s1 + 1);
		free(s1);
		s1 = NULL;
	}
	if (s2)
	{
		ft_strlcpy(f_str + s_s1, s2, s_s2 + 1);
		free(s2);
		s2 = NULL;
	}
	return (f_str);
}
