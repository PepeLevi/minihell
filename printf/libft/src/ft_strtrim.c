/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejimene <lejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:10:21 by lejimene          #+#    #+#             */
/*   Updated: 2023/01/10 15:04:25 by lejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check1(char c, char const *set1)
{
	int	i;

	i = 0;
	while (set1[i])
	{
		if (set1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		i;
	int		a;
	int		end;

	end = ft_strlen(s1) - 1;
	i = 0;
	a = 0;
	while (s1[i] != '\0' && ft_check1(s1[i], set))
		i++;
	while (i < end && ft_check1(s1[end], set))
		end--;
	p = malloc(((end - i) + 2) * sizeof(char));
	if (!p)
		return (NULL);
	while (i <= end)
	{
		p[a] = s1[i];
		i++;
		a++;
	}
	p[a] = '\0';
	return (p);
}
