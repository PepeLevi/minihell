/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejimene <lejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:25:54 by lejimene          #+#    #+#             */
/*   Updated: 2022/12/08 16:05:16 by lejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	counter;
	unsigned char	*u_s1;
	unsigned char	*u_s2;

	u_s1 = (unsigned char *) s1;
	u_s2 = (unsigned char *) s2;
	counter = 0;
	if (n == 0)
		return (0);
	while (counter < n && (u_s1[counter] || u_s2[counter]))
	{
		if (u_s1[counter] != u_s2[counter])
			return (u_s1[counter] - u_s2[counter]);
		counter++;
	}
	if (u_s1[counter] && !u_s2[counter] && counter < n)
		return (u_s1[counter]);
	if (!u_s1[counter] && u_s2[counter] && counter < n)
		return (-u_s2[counter]);
	return (0);
}
