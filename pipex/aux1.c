# include "pipex.h"

int open_file(char *file, int in_out)
{
    int fd;

    if (in_out == 0)
        fd = open(file, O_RDONLY);
    else if (in_out == 1)
        fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fd == -1)
        exit(0);
}