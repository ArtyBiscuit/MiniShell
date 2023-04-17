/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 05:03:08 by arforgea          #+#    #+#             */
/*   Updated: 2023/01/25 02:47:53 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ft_perror(char *msg, char **error, char *error_2)
{
	size_t	size;

	size = ft_strlen(msg);
	write(2, msg, size);
	if (error && error[0])
	{
		size = ft_strlen(error[0]);
		write(2, error[0], size);
	}
	else
	{
		size = ft_strlen(error_2);
		write(2, error_2, size);
	}
	write(2, "\n", 1);
}

int	open_file(char *file_path, int flags)
{
	int	fd;

	if (flags == 0)
		fd = open(file_path, O_RDONLY);
	if (flags == 1)
		fd = open(file_path, O_WRONLY | O_CREAT, 0644);
	return (fd);
}
