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

void	child1(t_pipex pipex, char **argv, char **env)
{
	if (access(argv[1], F_OK) == -1)
	{
		close_my_pipe(&pipex);
		my_exit2(5, 1, argv[1]);
	}
	pipex.infile = open(argv[1], O_RDONLY);
	pipex.permision = access(argv[1], R_OK);
	if (pipex.permision == -1)
	{
		close_my_pipe(&pipex);
		my_exit2(4, 1, pipex.arg);
	}
	dup2(pipex.infile, STDIN_FILENO);
	if (dup2 (pipex.pipe[1], STDOUT_FILENO) < 0)
		my_exit(1, 1);
	close_my_pipe(&pipex);
	close(pipex.infile);
	pipex.cmds = ft_split(argv[2], ' ');
	pipex.cmd = find_cmd(pipex.routes, pipex.cmds[0], &pipex);
	if (!pipex.cmd)
		exit(127);
	execve(pipex.cmd, pipex.cmds, env);
}

void	child2(t_pipex pipex, char **argv, int argc, char **env)
{
	pipex.outfile = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (pipex.outfile == -1)
	{
		close_my_pipe(&pipex);
		my_exit(4, 1);
	}
	pipex.permision = access(argv[argc - 1], W_OK);
	if (pipex.permision == -1)
	{
		close_my_pipe(&pipex);
		my_exit(4, 1);
	}
	dup2(pipex.pipe[0], STDIN_FILENO);
	dup2(pipex.outfile, STDOUT_FILENO);
	close(pipex.outfile);
	close_my_pipe(&pipex);
	pipex.cmds = ft_split(argv[3], ' ');
	if (!pipex.cmds)
		exit(127);
	pipex.cmd = find_cmd(pipex.routes, pipex.cmds[0], &pipex);
	if (!pipex.cmd)
		exit(127);
	else
		execve(pipex.cmd, pipex.cmds, env);
}
