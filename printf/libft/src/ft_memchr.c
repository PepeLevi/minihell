/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejimene <lejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:27:04 by lejimene          #+#    #+#             */
/*   Updated: 2022/12/07 14:52:44 by lejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	find;

	i = 0;
	str1 = (unsigned char *)str;
	find = (unsigned char) c;
	while (i < n)
	{
		if (str1[i] == find)
			return (&str1[i]);
		i++;
	}
	return (NULL);
}
