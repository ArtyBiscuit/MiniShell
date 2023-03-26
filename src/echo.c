/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:17:37 by arforgea          #+#    #+#             */
/*   Updated: 2023/03/26 06:35:46 by arty             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/minishell.h"

/*
struct typedef	s_arg
{
	char	*cmd = "echo";
	char	*str = "Lorem Ipsum";
	char	*flags "nhje";
}				t_arg;

struct typedef	s_arg
{
	char	*cmd = "|";
	char	*str = NULL;
	char	*flags NULL;
}				t_arg;

struct typedef	s_arg
{
	char	*cmd = "wc";
	char	*str = NULL;
	char	*flags "l";
}				t_arg;

struct typedef	s_arg
{
	char	*cmd = ">>";
	char	*str = "outfile";
	char	*flags NULL;
}				t_arg;

struct typedef	s_arg
{
	char	*cmd = "|";
	char	*str = NULL;
	char	*flags NULL;
}				t_arg;

struct typedef	s_arg
{
	char	*cmd = "cat";
	char	*str = "outfile";
	char	*flags NULL;
}				t_arg;

struct typedef	s_arg
{
	char	*cmd = "wc";
	char	*str = NULL;
	char	*flags "l";
}				t_arg;
*/

void	echo(char *str, char *flags)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	while (flags && flags[i])
	{
		if (flags[i] == 'n')
			f = 1;
		i++;
	}
	ft_putstr_fd(str, 1);
	if (f)
		return ;
	write(1, "\n", 1);
}
