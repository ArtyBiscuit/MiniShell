/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:11:43 by axcallet          #+#    #+#             */
/*   Updated: 2023/05/31 09:30:41 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*stock;

	if (s == NULL || len < 1)
		return (NULL);
	if (start > ft_strlen(s))
	{
		stock = ft_calloc(sizeof(char), 1);
		if (!stock)
			return (NULL);
		stock[0] = '\0';
		return (stock);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	stock = ft_calloc(sizeof(char), (len + 1));
	if (!stock)
		return (NULL);
	ft_strlcpy(stock, s + start, len + 1);
	if (stock[0] == '\0')
	{
		free(stock);
		return (NULL);
	}
	return (stock);
}
