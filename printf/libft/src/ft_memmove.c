/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejimene <lejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:19:26 by lejimene          #+#    #+#             */
/*   Updated: 2023/01/10 16:30:33 by lejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t size)
{
	size_t	i;
	char	*dest1;
	char	*src1;

	dest1 = (char *)dest;
	src1 = (char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest1 > src1)
	{
		while (size-- > 0)
			dest1[size] = src1[size];
	}
	else
	{
		while (i < size)
		{
			dest1[i] = src1[i];
			i++;
		}
	}
	return (dest);
}
