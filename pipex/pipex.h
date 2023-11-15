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

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>

typedef struct s_pipex
{
	char	**routes;
	char	**cmds;
	char	*cmd;
	int		pipe[2];
	int		infile;
	int		outfile;
	int		permision;
	pid_t	p1;
	pid_t	p2;
}t_pipex;

int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(char *src);
unsigned int	ft_strlen(const char *str);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strchr(const char *str, int c);
void			child1(t_pipex pipex, char **argv, char **env);
void			child2(t_pipex pipex, char **argv, int argc, char **env);
void			my_exit(int status, int error);
void			close_my_pipe(t_pipex *pipex);
char			*find_cmd(char **routes, char *cmd, t_pipex *pipex);
void			find_cmds(t_pipex *pipex, char **argv);
void			format(int argc);
char			**path_parsing(char **env);

#endif