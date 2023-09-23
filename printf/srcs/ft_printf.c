/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejimene <lejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:58:02 by lejimene          #+#    #+#             */
/*   Updated: 2023/08/01 14:01:22 by lejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_form(va_list args, const char form)
{
	int	len;

	len = 0;
	if (form == 'c')
		len += ft_putchar(va_arg(agrs, int));
	else if (form == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (form == 'p')
		len += ft_putptr(va_arg(args, unsigned long long));
	else if (form == 'd' || form == 'i')
		len += ft_putnbr2(va_arg(args, int));
	else if (form == 'u')
		len += ft_putunsigned(va_arg(args, unsigned int));
	else if (form == 'x' || form == 'X')
		len += ft_puthex(va_arg(args, unsigned int), format);
	else if (form == '%')
		len += ft_putpercent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_form(args, str[i + 1]);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
