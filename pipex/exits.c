/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiyarash <tiyarash@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 19:52:46 by tiyarash          #+#    #+#             */
/*   Updated: 2023/08/13 13:34:36 by tiyarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	my_put_str(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

void	my_exit(int status, int error)
{
	if (status == 1)
		write(2, "bash: Invalid number of arguments\n", 34);
	if (status == 2)
		write(2, "bash: error trying to allocate memory\n", 38);
	if (status == 3)
		write(2, "command not found\n", 18);
	if (status == 4)
		write(2, "pipex: Permission denied\n", 25);
	if (status == 5)
		write(2, "No such file or directory\n", 26);
	if (status == 6)
		write(2, "No PATH\n", 8);
	exit(error);
}

void	my_exit2(int status, int error, char *str)
{
	if (status == 5)
	{
		my_put_str(str);
		write(2, ": No such file or directory\n", 28);
	}
	if (status == 4)
	{
		my_put_str(str);
		write(2, ": Permission denied\n", 20);
	}
	if (status == 7)
	{
		my_put_str(str);
		write(2, ": command not found\n", 20);
	}
	exit(error);
}
