/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levijimenezrufes <levijimenezrufes@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:35:51 by levijimenez       #+#    #+#             */
/*   Updated: 2023/03/06 17:44:50 by levijimenez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	hexlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

void	puthex2(unsigned int num, const char form)
{
	if (num >= 16)
	{
		puthex2(num / 16, form);
		puthex2(num % 16, form);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (form == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (form == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	ft_puthex(unsigned int n, const char form)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		puthex2(n, form);
	return (hexlen(n));
}
