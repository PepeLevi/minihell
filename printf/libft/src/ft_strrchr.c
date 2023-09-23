/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejimene <lejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:25:14 by lejimene          #+#    #+#             */
/*   Updated: 2022/12/14 21:13:50 by lejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	int		len;
	int		counter;
	char	x;

	x = c;
	len = 0;
	len = ft_strlen(str);
	counter = 0;
	while (len != -1)
	{
		if (str[len] == x)
		{
			while (counter < len)
			{
				str++;
				counter++;
			}
			return (str);
		}
		len--;
	}
	if (x == '\0')
		return ((char *)str);
	return (NULL);
}
