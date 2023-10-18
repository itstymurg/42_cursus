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
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			count;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	if (dst < src)
	{
		count = 0;
		while (count < len)
		{
			ptr1[count] = ptr2[count];
			count++;
		}
	}
	else if (src < dst)
	{
		while (len--)
			ptr1[len] = ptr2[len];
	}
	return (dst);
}
