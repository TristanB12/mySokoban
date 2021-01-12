/*
** EPITECH PROJECT, 2019
** check_boxes
** File description:
** check if boxes can move
*/

#include <curses.h>
#include "sokoban.h"

pos_t check_box_up(int x, int y, char **map, pos_t player)
{
    if (map[y - 1][x] != '#' && map[y - 1][x] != 'X') {
        mvprintw(y, x, " ");
        mvprintw(y - 1, x, "X");
        map[y][x] = ' ';
        map[y - 1][x] = 'X';
        if (map[y + 1][x] != 'O')
            mvprintw(y + 1, x, " ");
        mvprintw(y, x, "P");
        player.y -= 1;
    }
    return player;
}

pos_t check_box_down(int x, int y, char **map, pos_t player)
{
    if (map[y + 1][x] != '#' && map[y + 1][x] != 'X') {
        mvprintw(y, x, " ");
        mvprintw(y + 1, x, "X");
        map[y][x] = ' ';
        map[y + 1][x] = 'X';
        if (map[y - 1][x] != 'O')
            mvprintw(y - 1, x, " ");
        mvprintw(y, x, "P");
        player.y += 1;
    }
    return player;
}

pos_t check_box_right(int x, int y, char **map, pos_t player)
{
    if (map[y][x + 1] != '#' && map[y][x + 1] != 'X') {
        mvprintw(y, x, " ");
        mvprintw(y, x + 1, "X");
        map[y][x] = ' ';
        map[y][x + 1] = 'X';
        if (map[y][x] - 1 != 'O')
            mvprintw(y, x - 1, " ");
        mvprintw(y, x, "P");
        player.x += 1;
    }
    return player;
}

pos_t check_box_left(int x, int y, char **map, pos_t player)
{
    if (map[y][x - 1] != '#' && map[y][x - 1] != 'X') {
        mvprintw(y, x, " ");
        mvprintw(y, x - 1, "X");
        map[y][x] = ' ';
        map[y][x - 1] = 'X';
        if (map[y][x + 1] != 'O')
            mvprintw(y, x + 1, " ");
        mvprintw(y, x, "P");
        player.x -= 1;
    }
    return player;
}