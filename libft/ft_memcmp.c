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
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			it;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	it = 0;
	while (it < n)
	{
		if ((ptr1[it] != ptr2[it]))
			return (ptr1[it] - ptr2[it]);
		it++;
	}
	return (0);
}
