/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chevrons_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:08:09 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/06 18:13:33 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"
#include "libft/libft.h"

int	check_word_before(char *str, int i)
{
	while (i >= 0)
	{
		if (i >= 0 && (str[i] != ' ' || str[i] != '\t' || str[i] != '|'))
			return (0);
		i--;
	}
	return (1);
}

char	*get_next_word(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] != ' ' && str[i] != '\t'))
			i++;
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i])
			return (ft_memcpy(next_word, &str[i], strlen_word(&str[i])));
	}
	return (NULL);
}
