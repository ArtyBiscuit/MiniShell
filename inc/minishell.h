/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:22:32 by arforgea          #+#    #+#             */
/*   Updated: 2023/03/24 09:59:30 by axcallet         ###   ########.fr       */
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

typedef struct s_cmd
{
	char			**cmd;
	char			*abs_path;
	char			**spe;
	char			*in;
	char			*out;
	struct s_cmd	*next;
	struct s_cmd	*back;
}				t_cmd;

typedef struct s_data
{
	char	**av;
	char	**env;
	int		ac;
	int		nb_pipe;
}				t_data;

//	########## FONCTIONS ##########

int		parsing(char *input);
int		strlen_word(char *str);
int		main(int argc, char **argv, char **envp);

char	*get_abs_path(char *cmd, char **envp);

void	free_tab(char **tab);
void	echo(char *str, char *flags);

//	########## END ##########

#endif
