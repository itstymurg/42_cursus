/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiyarash <tiyarash@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:01:29 by tiyarash          #+#    #+#             */
/*   Updated: 2023/10/01 13:01:17 by tiyarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (power > 0)
		return (nb * ft_recursive_power(nb, power - 1));
	return (nb);
}

int	putnbrunsigned(unsigned int n)
{
	unsigned long	i_a_ret[3];
	char			c;

	i_a_ret[0] = 0;
	i_a_ret[1] = n;
	while (n > 9)
	{
		n = n / 10;
		i_a_ret[0]++;
	}
	i_a_ret[0]++;
	i_a_ret[2] = i_a_ret[0];
	while (i_a_ret[0] > 0)
	{
		i_a_ret[0]--;
		c = (i_a_ret[1] / ft_recursive_power(10, i_a_ret[0])) + '0';
		i_a_ret[1] = i_a_ret[1] % ft_recursive_power(10, i_a_ret[0]);
		if (write(1, &c, 1) == -1)
			return (-1);
	}
	return (i_a_ret[2]);
}

int	while2(unsigned long int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	puthex(unsigned long n, char *base)
{
	int						i;
	unsigned long			a;
	char					c;
	int						ret;

	a = n;
	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	i = while2(n);
	ret = i;
	while (i > 0)
	{
		i--;
		c = base[a / ((unsigned long) ft_recursive_power(16, i))];
		a = a % ft_recursive_power(16, i);
		if (write(1, &c, 1) == -1)
			return (-1);
	}
	return (ret);
}
