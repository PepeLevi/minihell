#include "minishell.h"

int	my_cd(char **args, t_env *env)	// 
{
	int		cd_return;

	if (!args[1])						// go to home
		return(go_to_path(0, env));
	if (args > 2)						// i added this
		print_error(args);
	if (ft_strcmp(args[1], "-") == 0)	// - is the same as .. // has .. been implemented?
		cd_return = go_to_path(1, env);
	else
	{
		update_oldpwd(env);				// to use cd - , the old directory is saved here
		cd_return = chdir(args[1]);		//this will do the cd
		if (cd_return != 0)				// unsuccessful cd will return a non 0 value
			print_error(args);
	}
	return (cd_return);
}

// THIS CD seems to not check for if more arguments are passed

// continue with understanding what happens in the else
// my questions:
// 