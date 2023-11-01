/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiyarash <tiyarash@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 22:09:33 by tiyarash          #+#    #+#             */
/*   Updated: 2023/08/30 06:04:32 by tiyarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	main(int argc, char *argv[])
{
	unsigned int	length;

	if (argc >= 1)
	{
		length = ft_strlen(argv[0]);
		write(1, argv[0], length);
		write(1, "\n", 1);
	}
	return (0);
}
