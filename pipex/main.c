# include "pipex.h"

char    *find_cmd(char **routes, char *cmd)
{
    char	*tmp;
	char	*cmd_route;

	while (*routes)
	{
		tmp = ft_strjoin(*routes, "/");
		cmd_route = ft_strjoin(tmp, cmd);
		if (!cmd_route)
		{
			write(1, "Comando de ruta no encontrada", 29);
			return (NULL);
		}
		free(tmp);
		if (access(cmd_route, F_OK | X_OK) == 0)
			return (cmd_route);
		free(cmd_route);
		++routes;
	}
	if (access(cmd, F_OK | X_OK) == 0 && ft_strchr(cmd, '/'))
		return (cmd);
	else
	{
		write(1, "Command not found", 17);
		exit(127);
	}
	return (NULL);
}

void    find_cmds(t_pipex *pipex, char **argv)
{
    pipex->cmds = ft_split(argv[2], ' ');
	pipex->cmd = find_cmd(pipex->routes, pipex->cmds[0]);	
}

void child1(t_pipex pipex, char **argv, char **env)
{
    if (access(argv[1], F_OK) == -1)
	{
		close(pipex.pipe[0]);
		close(pipex.pipe[1]);
		exit(0);
	}
	pipex.infile = open(argv[1], O_RDONLY);
	pipex.permision = access(argv[1], R_OK);
	if (pipex.permision == -1)
	{
		close(pipex.pipe[0]);
		close(pipex.pipe[1]);
		write(1, "No Permissions", 14);
		exit(1);
	}
	dup2(pipex.infile, STDIN_FILENO);
	dup2(pipex.pipe[1], STDOUT_FILENO);
	//close(pipex.pipe[0]);
	close(pipex.pipe[1]);
	close(pipex.infile);
	execve(pipex.cmd, pipex.cmds, env);
}

void child2(int f2, char *cmd2)
{
	
}

void    format(int argc)
{
    if (argc != 5)
    {
        printf("Formato incorrecto");
        exit(0);
    }
}

int main (int argc, char *argv[], char *env[])
{
    t_pipex pipex;
    int f1;
    int f2;
    int path_exits;
    int ubi_path;
    char    **my_path;

    path_exits = 0;
    
    
    int i = 0;
    int j = 0;
    while (env[i])
    {
        if (ft_strncmp(env[i], "PATH=", 5) == 0)
        {
            path_exits = 1;
            my_path = ft_split(env[i], ':');
            my_path[0] = ft_substr( my_path[0], 5, ft_strlen(my_path[0]));
        }
        i++;
    }
    if (path_exits == 0)
    {
        write(1, "No PATH\n", 8);
        exit(1);
    }
    if(pipe(pipex.pipe))
        exit(1);
        
    pipex.p1 = fork();
    
    if (pipex.p1 == 0)
		first_child(pipex, argv, env);
		
	pipex.p2 = fork();
	
	if (pipex.p2 == 0)
		second_child(pipex, argv, argc, env);
		
	close(pipex.pipe[0]);
	close(pipex.pipe[1]);
	
	
	// waitpid(pipex.p1, NULL, 0);
	// waitpid(pipex.p2, &status, 0);
}