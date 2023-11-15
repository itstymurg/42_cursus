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

char	**path_parsing(char **env)
{
	int		i;
	int		path_exists;
	char	**my_path;

	i = 0;
	path_exists = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path_exists = 1;
			my_path = ft_split(env[i], ':');
			if (!my_path)
				my_exit(2, 1);
			my_path[0] = ft_substr(my_path[0], 5, ft_strlen(my_path[0]));
			if (!my_path[0])
				my_exit(2, 1);
		}
		i++;
	}
	if (path_exists == 0)
		my_exit(6, 1);
	return (my_path);
}
