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
#include <stdio.h>

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s || len == 0 || start >= ft_strlen(s))
		return (ft_strdup(""));
	i = (size_t)start;
	while (s[i] != '\0')
		i++;
	i = i - start;
	if (i < len)
		len = i;
	str = malloc (sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = (size_t)start;
	while (i < len && s[i] != '\0' && start < ft_strlen(s))
		str[i++] = s[j++];
	str[i] = '\0';
	return (str);
}
