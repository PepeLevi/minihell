/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levijimenezrufes <levijimenezrufes@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:29:12 by lejimene          #+#    #+#             */
/*   Updated: 2023/03/06 17:49:07 by levijimenez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

int	ft_printf(const char *str, ...);
int	ft_putstr(char *str);
int	ft_putptr(unsigned long long ptr);
int	ft_putnbr2(int nb);
int	ft_putunsigned(unsigned int n);
int	ft_puthex(unsigned int n, const char form);
int	ft_putpercent(void);

#endif