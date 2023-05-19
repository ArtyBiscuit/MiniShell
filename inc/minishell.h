/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:22:32 by arforgea          #+#    #+#             */
/*   Updated: 2023/05/19 09:40:56 by axcallet         ###   ########.fr       */
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

//	########## GLOBAL ##########
	
extern int	g_status;

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
	int		nb_cmd;
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
t_data	*dtt_init(t_data *data);
void	lst_destroy(t_exec *ptr);
t_data	*dtt_refile(t_data *data);
void	exec_lst_free(t_exec *ptr);
t_exec	*refile_exec(t_data *data, t_exec *dtt, char **tab, char *cmd);

//	input restructuration

char	*replace_variables(t_data *data);
void	input_restructure(t_data *data);
void	add_no_spaces(char *cmd, char *new_cmd, int *i, int *j); 

//	parsing

int		is_rdir(char c);
int		parsing(char *input);
int		strlen_word(char *str);
int		check_chevrons(char *str);
char	**input_to_tab(char *input);
int		get_pipes_number(char *cmd);
int		get_chevrons_number(char *cmd);
int		main(int argc, char **argv, char **envp);

//	signals

void	signals_heredoc(void);
void	signals_disabled(void);
void	mini_sigint(int signal);
void	mini_sigint_fork(int signal);
void	mini_sigquit_fork(int signal);
void	mini_sigint_heredoc(int signal);

//	heredoc

t_exec	*heredoc(t_data *data, t_exec *dtt, char **tab, char *cmd);

//	builtins

void	ft_echo(char *str, char *flags);
int		ft_pwd(t_exec *dtt);
int 	ft_env(t_exec *dtt, char **envp);
int		ft_cd(t_data *data, t_exec *dtt);
int		ft_unset(char ***envp, char *str);
int		ft_export(char ***envp, char *var);
int		ft_exit(t_data *data, t_exec *dtt);
int		check_after_fork(t_data *data, t_exec *dtt);
int		check_before_fork(t_data *data, t_exec *dtt);

//	other...

char	**ft_tab_dup(char **tab);

void	print_tab(char **arrey);

void	print_tab_sort(char **tab);

int		get_var_size(char *str);

int 	get_env_size(char **envp);

char	*get_abs_path(char *cmd, char **envp);

char	*add_spaces_rdir(char *str);

//char	*input_mod_var(t_data *data);

char	*remove_extra_spaces(char *cmd);

char	*remove_spaces_pipes(char *cmd);

char    *ft_secur_cat(char *s1, char *s2);

int		is_space(char c);

int		is_separator(char c);

int		check_syntax(char *str);

int		get_chars_number(char *str, char c);

char	**turbo_split(char *input, char c);

char	*get_next_word(char *str);

int		skip_argument(char *c);

t_exec	*left_chevrons(t_data *data, t_exec *dtt, char **tab, char *cmd);

t_exec	*right_chevrons(t_exec *dtt, char *cmd);

void	free_tab(char **tab);

void	echo(char *str, char *flags);

//	execution

int	exec_pipeline(t_data *data);

//	########## END ##########

#endif
