/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levijimenezrufes <levijimenezrufes@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:58:52 by levijimenez       #+#    #+#             */
/*   Updated: 2023/03/07 15:06:04 by levijimenez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	lenptr(unsigned long long size)
{
	int	len;

	len = 0;
	while (size != 0)
	{
		len++;
		size = size / 16;
	}
	return (len);
}

void	putptr(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		putptr(ptr / 16);
		putptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr + '0'), 1);
		else
			ft_putchar_fd((ptr - 10 + 'a'), 1);
	}
}

int	ft_putptr(unsigned long long ptr)
{
	int	len;

	len = 2;
	if (ptr == 0)
		len = write(1, "(nil)", 5);
	else
	{
		write(1, "0x", 2);
		putptr(ptr);
		len += lenptr(ptr);
	}
	return (len);
}
