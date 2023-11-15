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

void	close_my_pipe(t_pipex *pipex)
{
	close(pipex->pipe[1]);
	close(pipex->pipe[0]);
}

void	my_exit(int status, int error)
{
	if (status == 1)
		write(2, "bash: Invalid number of arguments\n", 34);
	if (status == 2)
		write(2, "bash: error trying to allocate memory\n", 38);
	if (status == 3)
		write(2, "Command not found\n", 18);
	if (status == 4)
		write(2, "Permission denied\n", 18);
	if (status == 5)
		write(2, "No such file in directory\n", 26);
	if (status == 6)
		write(2, "No PATH\n", 8);
	exit(error);
}

void	format(int argc)
{
	if (argc != 5)
	{
		printf("Formato incorrecto");
		my_exit(1, 1);
	}
}

char	*find_cmd(char **routes, char *cmd, t_pipex *pipex)
{
	char	*tmp;
	char	*cmd_route;

	while (*routes)
	{
		tmp = ft_strjoin(*routes, "/");
		cmd_route = ft_strjoin(tmp, cmd);
		if (!cmd_route)
		{
			write(2, "Comando de ruta no encontrada", 29);
			return (NULL);
		}
		free(tmp);
		if (access(cmd_route, F_OK | X_OK) == 0)
			return (cmd_route);
		free(cmd_route);
		++routes;
	}
	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	close_my_pipe(pipex);
	my_exit(3, 127);
	return (NULL);
}

void	find_cmds(t_pipex *pipex, char **argv)
{
	pipex->cmds = ft_split(argv[2], ' ');
	pipex->cmd = find_cmd(pipex->routes, pipex->cmds[0], pipex);
}
