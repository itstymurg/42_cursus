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
void    *ft_memcpy(void *s1, const void *s2, unsigned int n)
{
        unsigned int    i;
        unsigned char   *s;
        const unsigned char *src;

        src = s2;
        s = s1;
        i = 0;
        while (i < n)
        {
                *s++ = *src++;
                i++;
        }
        return (s1);
}
