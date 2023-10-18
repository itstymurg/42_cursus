/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiyarash <tiyarash@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 05:21:53 by tiyarash          #+#    #+#             */
/*   Updated: 2023/08/30 06:06:31 by tiyarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	digit[10];
	int		sign;
	int		i;

	if (fd < 0)
		return ;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	i = 0;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		write(fd, "-", 1);
	}
	while (n)
	{
		digit[i++] = '0' + (n % 10 * sign);
		n = n / 10;
	}
	while (i)
		write(fd, &digit[--i], 1);
}
