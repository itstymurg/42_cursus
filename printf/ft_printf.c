/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiyarash <tiyarash@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:49:45 by tiyarash          #+#    #+#             */
/*   Updated: 2023/10/04 09:13:58 by tiyarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	writing(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = putonechar(va_arg(args, int));
	else if (c == 's')
		count = putmystr(va_arg(args, const char *));
	else if (c == 'p')
		count = ft_putptr(va_arg(args, unsigned long));
	else if (c == 'd')
		count = putmynbr(va_arg(args, int));
	else if (c == 'i')
		count = putmynbr(va_arg(args, int));
	else if (c == 'u')
		count = putnbrunsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		count = puthex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		count = puthex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		count = putonechar(c);
	if (count == -1)
		return (-1);
	return (count);
}

int	reading(const char *str, va_list args, int count)
{
	int	i;
	int	aux;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			aux = count;
			count += writing(args, str[++i]);
			if (aux > count)
				return (-1);
		}
		else
		{
			if (write (1, &str[i], 1) == -1)
				return (-1);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, str);
	count = 0;
	i = 0;
	count = reading(str, args, count);
	va_end(args);
	return (count);
}
