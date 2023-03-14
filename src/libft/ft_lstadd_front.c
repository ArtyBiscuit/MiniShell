/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:40:28 by axcallet          #+#    #+#             */
/*   Updated: 2023/03/14 11:48:44 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new_lst)
{
	t_list	*temp;

	if (new == NULL)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		temp = *lst;
		*lst = new;
		new->next = temp;
	}
}
