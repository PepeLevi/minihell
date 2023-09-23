#include "minishell.h"

int		my_pwd(void)
{
	char	path[PATH_MAX]; // PATH_MAX is defined in limits.h
	// PATH_MAX represents the max number of chars a pathname can have + NULL

	// get current-working-directory: (lib function)
	if (getcwd(path, PATH_MAX))	// input into store_path with size of buffer
	{
		ft_putendl_fd(path, 1);
		return (0);				// SUCESSFUL
	}
	else
		return (1);				// FAIL
}