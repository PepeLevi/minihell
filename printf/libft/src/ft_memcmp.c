/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejimene <lejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:44:51 by lejimene          #+#    #+#             */
/*   Updated: 2022/12/14 20:31:42 by lejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s;
	const unsigned char	*d;
	size_t				counter;

	s = (const unsigned char *)s1;
	d = (const unsigned char *)s2;
	counter = 0;
	while (counter < n)
	{
		if (s[counter] != d[counter])
			return (s[counter] - d[counter]);
		counter++;
	}
	return (0);
}
