#include "../pipex.h"

int   child_process(char **argv, int *fd_array, char **env_vars)
{
    int fd;

    ft_printf("child is beginning \n");
    fd = open(argv[1],O_RDONLY);
    if(!fd)
        return(0);
    dup2(fd, 0);
    dup2(fd_array[1], 1);
    close(fd_array[0]);
    (void) env_vars;
    return(0);
}

int   parent_process(char **argv, int *fd_array, char **env_vars)
{
    int fd;

    fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
    if(!fd)
        return(0);
    dup2(fd, 0);
    dup2(fd_array[1], 1);
    close(fd_array[0]);
    (void) env_vars;
    return(0);
}