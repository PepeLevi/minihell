/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejimene <lejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:05:45 by lejimene          #+#    #+#             */
/*   Updated: 2023/08/01 13:59:43 by lejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(unsigned int nspa, unsigned int size)
{
	char	*p;
	int		bzero;
	int		i;

	i = 0;
	p = malloc(nspa * size);
	bzero = nspa * size;
	if (p == NULL)
		return (NULL);
	while (i < bzero)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
