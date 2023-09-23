/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejimene <lejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:13:19 by lejimene          #+#    #+#             */
/*   Updated: 2023/01/10 18:08:44 by lejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_check(char *str1, int counter1, int check1, long n1)
{
	if (n1 != 0)
		str1 = malloc(sizeof(char) * (counter1 + 1));
	else
		return (str1 = ft_strdup("0"));
	if (!str1)
		return (0);
	check1 = 0;
	if (n1 < 0)
	{
		check1++;
		n1 = -n1;
	}
	str1[counter1] = '\0';
	while (--counter1)
	{
		str1[counter1] = (n1 % 10) + '0';
		n1 /= 10;
	}
	if (check1 == 1)
		str1[0] = '-';
	else
		str1[0] = (n1 % 10) + '0';
	return (str1);
}

char	*ft_itoa(int n)
{
	int		counter;
	long	a;
	long	b;
	char	*str;
	int		check;

	str = NULL;
	check = 0;
	counter = 0;
	a = n;
	b = n;
	if (a < 0)
	{
		counter++;
		a = -a;
	}
	while (a > 0)
	{
		counter++;
		a /= 10;
	}
	if (n == 0)
		counter++;
	return (ft_check(str, counter, check, b));
}
