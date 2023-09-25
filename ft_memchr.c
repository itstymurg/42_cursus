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
//BIEN
void *ft_memchr(const void *str, int chr, size_t n)
{
    const unsigned char *p;
    unsigned char       c_a_buscar;
    size_t              i;

    p = str;
    c_a_buscar = (unsigned char)chr;
    i = 0;
    while (i < n)
    {
        if (*p == c_a_buscar)
            return ((void *)(p));
            p++;
            i++;
    }
    return (0);
}