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

int	ft_putptr(unsigned long nbr)
{
	int	counter;
	int	aux;

	counter = write(1, "0x", 2);
	if (counter < 2)
		return (-1);
	aux = counter;
	counter += puthex(nbr, "0123456789abcdef");
	if (aux > counter)
		return (-1);
	return (counter);
}
