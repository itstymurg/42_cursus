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
void	*ft_memset(void *p, int c, unsigned int n)
{
	unsigned int	i;
	unsigned char	*s;
	unsigned char	chr;

	s = p;
	i = 0;
	chr = (unsigned char)c;
	while (i < n)
	{
		s[i] = c;
		i++;
	}
	return (p);
}
