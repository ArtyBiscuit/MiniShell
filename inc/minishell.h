/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:22:32 by arforgea          #+#    #+#             */
/*   Updated: 2023/03/14 15:28:07 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINISHELL_H
# define MINISHELL_H
# include "../src/libft/libft.h"

char	*get_abs_path(char *cmd, char **envp);
void	free_tab(char **tab);

#endif
