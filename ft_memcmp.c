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
int ft_memcmp(const void *str1, const void *str2, size_t num)
{
    const unsigned char *a;
    const unsigned char *b;
    size_t              i;

    a = (const unsigned char *)str1;
    b = (const unsigned char *)str2;
    i = 0;
    while (i < num)
    {
        if (*a < *b)
            return (-1);
        if (*a > *b)
            return (1);
        i++;
        a++;
        b++;
    }
    return (0);
}