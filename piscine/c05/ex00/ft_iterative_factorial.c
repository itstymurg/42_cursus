/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiyarash <tiyarash@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:42:23 by tiyarash          #+#    #+#             */
/*   Updated: 2023/08/28 19:05:54 by tiyarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	aux;

	if (nb < 0)
		return (0);
	i = 1;
	aux = 1;
	while (i <= nb)
	{
		aux *= i;
		i++;
	}
	return (aux);
}
/*
int main(){
    printf("%d", ft_iterative_factorial(5));
}*/
