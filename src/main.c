/*
** EPITECH PROJECT, 2019
** main
** File description:
** main of my_sokoban
*/

#include "sokoban.h"
#include "my.h"
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <curses.h>

char *set_open_file(char **av, int fd)
{
    char *buffer;
    struct stat stats;
    int size = 0;

    stat(av[1], &stats);
    size = stats.st_size;
    buffer = malloc(sizeof(char) * size + 1);
    read(fd, buffer, size);
    buffer[size] = '\0';
    return buffer;
}

void display_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("    ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    map file representing the warehouse map");
    my_putstr(", containing ‘#’ for walls, ‘P’ for the player, ");
    my_putstr("‘X’ for boxes and ‘O’ for storage locations.\n");
}

int main(int ac, char **av)
{
    char *str;
    char **map;
    int stat = 0;
    int fd = 0;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        display_help();
        return 42;
    }
    if (ac != 2 || check_readable(av[1]) == 84)
        return 84;
    fd = open(av[1], O_RDONLY);
    str = set_open_file(av, fd);
    if (errors(str) > 0)
        return 84;
    map = put_str_in_tab(str);
    stat = sokoban(map, str);
    endwin();
    return stat;
}
