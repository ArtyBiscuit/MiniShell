/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:22:32 by arforgea          #+#    #+#             */
/*   Updated: 2023/04/22 13:20:02 by axcallet         ###   ########.fr       */
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
typedef struct s_exec	t_exec;
typedef struct s_data	t_data;

struct	s_exec
{
	int		fd_in;
	int		fd_out;
	char	*abs_path;
	char	**full_cmd;
	char	*cmd;
	t_exec	*next;
	t_exec	*back;
};

struct s_data
{
	char	*input;
	char	**envp;
	t_exec	*dtt;
};
//	**********	 DEBUG ! **********
void	DB_print_dtt(t_data *data);
void	DB_print_tab(char **tab);
//	########## FONCTIONS ##########

//	lst-init
t_exec	*exec_lst_init(int nb);
void	exec_lst_free(t_exec *ptr);
void	lst_destroy(t_exec *ptr);

t_data	*dtt_init(t_data *data);
t_data	*dtt_refile(t_data *data);
t_exec	*refile_exec(t_data *data, t_exec *dtt, char *cmd);
//	parsing
char	**input_to_tab(char *input);
int		parsing(char *input);
int		strlen_word(char *str);
int		main(int argc, char **argv, char **envp);
int		is_rdir(char c);

int		get_chevrons_number(char *cmd);
int		get_pipes_number(char *cmd);
int		check_chevrons(char *str);
//	other...
char	*get_abs_path(char *cmd, char **envp);

char	*add_spaces_rdir(char *str);

char	*remove_spaces_pipes(char *cmd);

int		is_space(char c);

int		check_syntax(char *str);

int		get_chars_number(char *str, char c);

char	**turbo_split(char *input, char c);

char	*get_next_word(char *str);

int		skip_argument(char *c);

void	free_tab(char **tab);
void	echo(char *str, char *flags);

//	########## END ##########

#endif
