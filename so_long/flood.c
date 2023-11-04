#include "so_long.h"

// int searcher(char *str, int *nwalls, int *nenemies, int *ncoins)
// {
//     int i;
//     i = 0;

//     if(*str == '\0')
//         return(1);
//     while (str[i])
//     {
//         if (str[i] == '1')
//             nwalls++;
//         if (str[i] == 'N')
//             nenemies++;
//         if (str[i] == 'C')
//             ncoins++;
//     }
//     return (0);
// }

// int flood(char *map, t_system *sys)
// {
//     int nwalls, nenemies, ncoins;
//     int fd;
//     fd = open(map, O_RDONLY);

//     while (searcher(get_next_line(fd), &nwalls, &nenemies, &ncoins) == 0)
//         printf("a");
//     sys->window.wall = malloc(nwalls * sizeof(t_box));
//     sys->window.enemy = malloc(nenemies * sizeof(t_box));
//     sys->window.colect = malloc(ncoins * sizeof(t_box));
//     return 0;
// }