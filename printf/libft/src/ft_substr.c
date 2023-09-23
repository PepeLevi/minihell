/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejimene <lejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:37:37 by lejimene          #+#    #+#             */
/*   Updated: 2023/01/10 16:51:31 by lejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	char	*temp;

	temp = (char *)s;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(temp))
	{
		p = malloc(sizeof(char));
		if (!p)
			return (NULL);
		p[0] = '\0';
		return (p);
	}
	if (len > ft_strlen(temp + start))
		len = ft_strlen(temp + start);
	p = malloc(sizeof(char) * len + 1);
	if (!p)
		return (NULL);
	ft_strlcpy(p, temp + start, len + 1);
	return (p);
}
