/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:22:32 by arforgea          #+#    #+#             */
/*   Updated: 2023/03/26 12:07:45 by arforgea         ###   ########.fr       */
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
typedef struct	s_exec	t_exec;
typedef struct	s_rdir	t_rdir;
typedef struct	s_cmd	t_cmd;

struct	s_exec
{
	t_cmd	*cmd;
	t_rdir	*rdir;
	t_exec	*next;
	t_exec	*back;
};

struct	s_rdir
{
	char	*rdir;
	char	*infile;
	char	*outfile;
	t_rdir	*next;
	t_rdir	*back;
};

struct	s_cmd
{
	char	*abs_path;
	char	**full_cmd;
	char	*cmd;
};

/*
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
*/

typedef struct s_data
{
	char	**av;
	char	**env;
	int		ac;
	int		nb_pipe;
}				t_data;

//	########## FONCTIONS ##########

//	lst-init
t_exec	*exec_lst_init(int nb);
t_rdir	*rdir_lst_init(int nbr);
void	exec_lst_free(t_exec *ptr);
void	rdir_lst_free(t_rdir *ptr);
void	lst_destroy(t_exec *ptr);




//	parsing
int		parsing(char *input);
int		strlen_word(char *str);
int		main(int argc, char **argv, char **envp);

//	other...
char	*get_abs_path(char *cmd, char **envp);

void	free_tab(char **tab);
void	echo(char *str, char *flags);

//	########## END ##########

#endif
