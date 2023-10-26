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

char	*ft_strnstr(const char *str, const char *buscar, size_t len)
{
	size_t	len_buscar;

	len_buscar = ft_strlen((char *)buscar);
	if (len_buscar == 0)
		return ((char *)str);
	while (*str && len >= len_buscar)
	{
		if (ft_strncmp((char *)str, (char *)buscar, len_buscar) == 0)
			return ((char *)str);
		str++;
		len--;
	}
	return (0);
}
