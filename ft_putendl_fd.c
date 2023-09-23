#include "minishell.h"

// print a string + \n to a given fd descriptor.
void	ft_putendl_fd(char *s, int fd)
{
	int pos;

	pos = 0;

//	ERROR handling
	if (s == NULL)
		return ;


	while (s[pos] != '\0')
	{
		write(fd, &s[pos], 1);		// print string
		pos++;
	}
	write(fd, "\n", 1);				// print new line
}