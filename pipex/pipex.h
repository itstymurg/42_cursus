#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include<sys/stat.h>

typedef struct s_pipex
{
    char    **routes;
    char    **cmds;
    char    *cmd;
    int     pipe[2];
    int     infile;
    int     outfile;
    int     permision;
    pid_t   p1;
    pid_t   p2;
    
    
}t_pipex;


int             open_file(char *file, int in_out);
int	            ft_strncmp(const char *s1, const char *s2, size_t n);
char	        **ft_split(char const *s, char c);
char	        *ft_substr(char const *s, unsigned int start, size_t len);
char	        *ft_strdup(char *src);
unsigned int	ft_strlen(const char *str);

#endif