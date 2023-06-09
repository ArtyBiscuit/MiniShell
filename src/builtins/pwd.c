/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:23:52 by axcallet          #+#    #+#             */
/*   Updated: 2023/06/08 10:26:26 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_pwd(void)
{
	char	pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	ft_putstr_fd(pwd, 1);
	ft_putstr_fd("\n", 1);
	g_status = 0;
	return (1);
}
