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

static int	how_many(const char *str, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i++])
	{
		if (str[i] == c && str[i + 1] != '\0')
			j++;
	}
	j++;
	return (j);
}

static void	lengths(int *vector, const char *str, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (k != 0)
				vector[k] = i - j - 1;
			else
				vector[k] = i - j;
			j = i;
			k++;
		}
		i++;
	}
	vector[k] = i - j - 1;

}

/*char	*put_letters(char **array, int i, int length, const char *str)
{
	int		j;
	int		k;
	char	*aux;

	j = i;
	k = 0;
	while()
		while (j < i + length)
		{
			aux[k] = str[j];
			j++;
			k++;
		}
	aux[k] = '\0';
	return (aux);
}*/

static void	mallocs(char **array, int *vector, int a)
{
	int	i;

	i = 0;
	while (i < a)
	{
		array[i] = malloc((sizeof(char) * vector[i]) + 1);
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		*quantity;
	int		a;
	int		i;
	int		m;
	int		n;

	a = how_many(s, c);
	array = malloc(sizeof(char *) * a);
	if (array == NULL)
		return 0;
	quantity = malloc(sizeof(int) * a);
	if (quantity == NULL)
		return 0;
	lengths(quantity, s, c);
	mallocs(array, quantity, a);
	i = 0;
	m = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (n < quantity[m])
			{
				array[m][n] = s[i];
				n++;
				i++;
			}

			n = 0;
			m++;
			
		}else {
			i++;
		}
	}
	return (array);
}
/*
int	main(void)
{
	char **a = ft_split("hola,que,tal", ',');
	for (size_t i = 0; i < 5; i++)
	{
		printf("\n%s", a[i]);
	}
	free(a);
}*/