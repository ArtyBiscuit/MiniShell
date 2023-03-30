#include "../inc/minishell.h"
#include <unistd.h>

void	rdir_set_content(t_rdir *link, char *rdir, char *infile, char *outfile)
{
	link->rdir = rdir;
	link->infile = infile;
	link->outfile = outfile;
	return ;
}
