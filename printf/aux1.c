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

int	putonechar(char c)
{
	if (write (1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	putmystr(const char *c)
{
	size_t			i;

	if (!c)
		c = "(null)";
	i = 0;
	while (c[i])
	{
		if (write (1, &c[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	while1(unsigned long n)
{
	unsigned long	i;

	i = 0;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	putmynbr(long n)
{
	unsigned long	i_a_ret[3];
	char			c;

	i_a_ret[2] = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n *= -1;
		i_a_ret[2]++;
	}
	i_a_ret[1] = n;
	i_a_ret[0] = while1(n);
	i_a_ret[2] += ++i_a_ret[0];
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
