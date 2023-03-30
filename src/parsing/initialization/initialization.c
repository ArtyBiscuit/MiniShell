#include "../../../inc/minishell.h"

t_exec	*dtt_init(char *input)
{
	int		i;
	char	**tab;
	t_exec	*tmp;
	t_exec	*main;
	
	i = 0;
	main = malloc(sizeof(t_exec) * get_pipes_number(input));
	if (!main)
		return (NULL);
	tab = split_pipes(input);
	while (tab[i])
	{
		if (check_chevrons(tab[i]) == 1)
		{
			 
		}
	}
}
