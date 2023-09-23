/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejimene <lejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:20:48 by lejimene          #+#    #+#             */
/*   Updated: 2023/01/10 15:18:46 by lejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	counter;
	size_t	counter2;
	size_t	sizedest;
	size_t	sizesrc;

	sizedest = 0;
	sizesrc = 0;
	counter = 0;
	counter2 = 0;
	counter2 = ft_strlen(dest);
	sizedest = ft_strlen(dest);
	while (src[sizesrc] != '\0')
		sizesrc++;
	while (counter2 + 1 < size && src[counter] != '\0')
	{
		dest[counter2] = src[counter];
		counter++;
		counter2++;
	}
	dest[counter2] = '\0';
	if (size <= sizedest)
		return (sizesrc + size);
	else
		return (sizedest + sizesrc);
}
