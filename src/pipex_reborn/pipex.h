/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:39:05 by arforgea          #+#    #+#             */
/*   Updated: 2023/01/25 03:17:08 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <time.h>
# include <sys/types.h>

void	ft_perror(char *msg, char **error, char *error_2);
int		exec_pipeline(int argc, char *argv[], char *envp[]);
char	**split_cmd_flags(char *all_cmd);
int		open_file(char *file_path, int flags);
char	**get_path_var(char *envp[]);
char	*get_good_path(char *cmd, char **lst_path);
#endif

/*-----------------------------------------------
 *PIPEX
 * -> char	**get_path_var(char *envp[]);
 * 	\----------------------------------------
 * 	\ get "PATH" environment variable path bin from "envp"
 * 	\		ex[envp = "**envp"]
 * 	\ 		return = **array
 * 	\		\ ex["/nfs/homes/arforgea/bin",
 * 	\		\	"/usr/local/sbin",
 * 	\		\	"/usr/local/bin",
 * 	\		\	"/usr/sbin"...
 * 	\		\--------------------------------
 * 	\ return "NULL" if no "PATH" environment variable has been found.
 * 	\----------------------------------------
 *
 * -> char	*get_good_path(char *cmd, char **lst_path);
 * 	\----------------------------------------
 * 	\ get the right path for "cmd" from "lst_path" (contains a path list).
 * 	\ 		ex[cmd = "ls", lst_path = "**lst"]
 * 	\		return = "/usr/bin/ls" (MALLOC !).
 * 	\ return "NULL" if no path has been found
 * 	\----------------------------------------
 *
 *-------------------------*/
