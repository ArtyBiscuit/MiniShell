/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:22:32 by arforgea          #+#    #+#             */
/*   Updated: 2023/03/16 15:34:54 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	########## START ##########

#ifndef MINISHELL_H
# define MINISHELL_H

//	########## INCLUDES ##########

# include "../src/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/time.h>
# include <termios.h>

//	########## STRCTURE ##########

typedef struct	s_main
{
	char	**cmd;
	char	*abs_path;
	char	*spe;
	char	*rlt_file;
	t_main	*next;
	t_main	*back;
}				t_main;

typedef struct	s_data
{
	char	**av;
	char	**env;
	int		ac;
	t_main	*lst_head;
}				t_data;

//	########## FONCTIONS ##########

int		main(int argc, char **argv, char **envp);

char	*get_abs_path(char *cmd, char **envp);

void	free_tab(char **tab);
void	echo(char *str, char *flags);

//	########## END ##########

#endif
