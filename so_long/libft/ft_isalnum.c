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

//BIEN
#include "libft.h"

int	ft_isalnum(int n)
{
	int	i;

	if (n < 0)
		n *= -1;
	i = 0;
	if (!((n >= 'A' && n <= 'Z')
			|| (n >= 'a' && n <= 'z') || (n >= '0' && n <= '9')))
		return (0);
	return (1);
}
