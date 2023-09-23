/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejimene <lejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:04:09 by lejimene          #+#    #+#             */
/*   Updated: 2023/08/16 17:15:05 by lejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	counter;
	int	a;
	int	b;

	counter = 0;
	a = 1;
	b = 0;
	while ((str[counter] >= 9 && str[counter] <= 13) || str[counter] == 32)
		counter++;
	if (str[counter] == '-' || str[counter] == '+')
	{
		if (str[counter] == '-')
			a *= -1;
		counter++;
	}
	while (str[counter] >= '0' && str[counter] <= '9')
	{
		b = b * 10 + str[counter] - '0';
		counter++;
		if (b > 2147483647)
			return (2147483647);
		if (b < -2147483647)
			return (-2147483648);
	}
	return (a * b);
}

/* int main()
{
	printf("%d", ft_atoi("546:5"));
} */