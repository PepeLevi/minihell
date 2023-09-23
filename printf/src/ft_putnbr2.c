/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levijimenezrufes <levijimenezrufes@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 16:17:01 by levijimenez       #+#    #+#             */
/*   Updated: 2023/03/07 18:14:21 by levijimenez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_putchar2(char c)
{
	write(1, &c, 1);
	return (1);
}

int	putnbr(int nb, int len)
{
	if (nb == -2147483648)
	{
		len += ft_putchar2('-');
		len += ft_putchar2('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		len += ft_putchar2('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		len = putnbr((nb / 10), len);
		len = putnbr((nb % 10), len);
	}
	else
	{
		len += ft_putchar2((nb + 48));
	}
	return (len);
}

int	ft_putnbr2(int nb)
{
	int	len;

	len = 0;
	len += putnbr(nb, len);
	return (len);
}
