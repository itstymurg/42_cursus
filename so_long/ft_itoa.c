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

#include "so_long.h"
#include <stdio.h>
//BIEN
static int	calculate_itoa_array_size(int n)
{
	int	array_size;

	array_size = 1;
	if (n < 0)
		array_size++;
	while (n)
	{
		n = n / 10;
		array_size++;
	}
	return (array_size);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		array_size;
	int		sign;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 1;
	array_size = calculate_itoa_array_size(n);
	ptr = malloc(sizeof(char) * array_size);
	if (!ptr)
		return (NULL);
	if (n < 0)
	{
		sign = -1;
		ptr[0] = '-';
	}
	ptr[--array_size] = '\0';
	while (n)
	{
		ptr[--array_size] = '0' + (n % 10 * sign);
		n = n / 10;
	}
	return (ptr);
}
