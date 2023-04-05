/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_set_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 09:37:38 by axcallet          #+#    #+#             */
/*   Updated: 2023/04/05 11:44:32 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <unistd.h>

void	rdir_set_content(t_rdir *link, char *rdir, char *infile, char *outfile)
{
	link->rdir = rdir;
	link->infile = infile;
	link->outfile = outfile;
	return ;
}
