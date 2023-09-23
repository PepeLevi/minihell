/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejimene <lejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:18:51 by lejimene          #+#    #+#             */
/*   Updated: 2022/12/07 14:17:37 by lejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	*ft_memset(void *str, int x, size_t size)
{
	size_t	i;
	char	*str1;

	i = 0;
	str1 = (char *)str;
	while (i < size)
	{
		str1[i] = x;
		i++;
	}
	return (str1);
}
