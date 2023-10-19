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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int				putmynbr(long n);
int				putmystr(const char *c);
int				putonechar(char c);
long int		ft_recursive_power(int nb, int power);
int				putnbrunsigned(unsigned int n);
int				puthex(unsigned long n, char *base);
int				writing(va_list args, char c);
int				ft_printf(const char *str, ...);
int				ft_putptr(unsigned long nbr);
int				while1(unsigned long n);

#endif
