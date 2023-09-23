/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejimene <lejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:03:42 by lejimene          #+#    #+#             */
/*   Updated: 2023/01/10 15:02:15 by lejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*p;
	int		i;
	int		a;

	i = -1;
	a = -1;
	size = ft_strlen(s1) + ft_strlen(s2);
	p = malloc(sizeof(char) * size + 1);
	if (!p)
		return (NULL);
	while (i++, a++, s1[i] != '\0')
	{
		p[a] = s1[i];
	}
	i = 0;
	while (s2[i] != '\0')
	{
		p[a] = s2[i];
		i++;
		a++;
	}
	p[a] = '\0';
	return (p);
}
