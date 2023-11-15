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

int	main(int argc, char *argv[], char *env[])
{
	t_pipex	pipex;
	int		status;

	format(argc);
	pipex.routes = path_parsing(env);
	if (pipe(pipex.pipe))
		exit(1);
	pipex.p1 = fork();
	if (pipex.p1 == 0)
		child1(pipex, argv, env);
	pipex.p2 = fork();
	if (pipex.p2 == 0)
		child2(pipex, argv, argc, env);
	close_my_pipe(&pipex);
	waitpid(pipex.p1, 0, 0);
	waitpid(pipex.p2, &status, 0);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	exit(0);
}
