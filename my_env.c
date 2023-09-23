#include "minishell.h"


// env shows the current enviroment
int		my_env(t_env *env)				// input linked list t_env as defined in .h file
{
	while (env)	// iterate until last node
	{
		ft_putendl(env->value);			// print value
		env = env->next;				// go to next node
	}
	return (0);
}