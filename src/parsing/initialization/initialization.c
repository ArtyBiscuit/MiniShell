#include "../../../inc/minishell.h"
#include <stdlib.h>

t_exec	*dtt_init(char *input)
{
	int		i;
	char	**tab;
	t_exec	*tmp;
	t_exec	*main;
	
	i = 0;
	
	main = exec_lst_init(get_pipes_number(input));
	if (!main)
		return (NULL);
	tmp = main;
	tab = split_pipes(input);
	while (tab[i])
	{
		if (check_chevrons(tab[i]))
			tmp->rdir = rdir_lst_init(get_chevrons_number(tab[i]));
		else
			tmp->cmd = malloc(sizeof(t_cmd) * 1);
		tmp = tmp->next;
		i++;
	}
//	free_tab(tab);
	return (main);
}
