/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejimene <lejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:11:12 by lejimene          #+#    #+#             */
/*   Updated: 2022/12/14 19:07:31 by lejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_alocate2(char const *s1, char e, int counter1)
{
	int	a;

	a = 0;
	while (s1[counter1] != e && s1[counter1])
	{
		counter1++;
		a++;
	}
	return (a);
}

int	ft_alocate(int counter1, char const *s1, char e)
{
	int	a;

	a = 0;
	while (s1[counter1])
	{
		if (s1[counter1] != e)
		{
			a++;
			while (s1[counter1] != e && s1[counter1])
				counter1++;
		}
		else
			counter1++;
	}
	return (a);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		counter;
	int		counter2;
	char	**new;
	int		size;

	i = 0;
	size = ft_alocate(0, s, c);
	counter2 = 0;
	counter = -1;
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	while (counter++ < size - 1)
	{
		while (s[i] == c)
			i++;
		counter2 = ft_alocate2(s, c, i);
		new[counter] = ft_substr(s, i, counter2);
		if (!new)
			return (NULL);
		i += counter2;
	}
	new[counter] = 0;
	return (new);
}
