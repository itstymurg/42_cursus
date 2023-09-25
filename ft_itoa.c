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
#include <stdio.h>
//BIEN
int	ft_recursive_power(long int nb, long int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (power > 0)
		return (nb * ft_recursive_power(nb, power - 1));
	return (nb);
}

int	buscar_contador(long int nb, long int contador)
{
	long int	nbr;

	nbr = nb;
	if (nb < 0)
	{
		nbr = -nbr;
		contador++;
		buscar_contador(nbr, contador);
	}
	nbr /= 10;
	contador++;
	while (nbr > 0)
	{
		nbr /= 10;
		contador++;
	}
	return (contador);
}

char	*separar(char *str, long int i, long int contador, long int number)
{
	if (number < 0)
	{
		number *= -1;
		contador--;
	}
	
	while (contador != 0)
	{
		long int divisor = ft_recursive_power(10, contador - 1);
        str[i] = number / divisor + '0';
        number = number % divisor;
        contador--;
        i++;
        str[i] = '\0';
	}
	return (str);
}

char	*ft_itoa(long int number)
{
	long int		contador;
	char			*str;
	long int		i;

	contador = 0;
	i = 0;
	contador = buscar_contador(number, contador);
	str = (char *)malloc((contador * sizeof(char)) + 1);
	if (number < 0)
		str[i++] = '-';
	separar(str, i, contador, number);
	return (str);
}
/*
int	main(void)
{
	printf("%s", ft_itoa(-2147483648));
}*/