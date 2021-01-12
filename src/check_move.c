/*
** EPITECH PROJECT, 2019
** check_move
** File description:
** check move of player
*/

#include "sokoban.h"
#include <ncurses.h>
#include <stdio.h>

pos_t check_move_up(pos_t player, char **map)
{
    int x = player.x;
    int y = player.y;

    if (map[y - 1][x] != '#' && map[y - 1][x] != 'X') {
        if (map[y][x] != 'O')
            mvprintw(y, x, " ");
        mvprintw(y - 1, x, "P");
        player.y -= 1;
    }
    if (map[y - 1][x] == 'X') {
        player = check_box_up(x, y - 1, map, player);
    }
    return player;
}

pos_t check_move_down(pos_t player, char **map)
{
    int x = player.x;
    int y = player.y;

    if (map[y + 1][x] != '#' && map[y + 1][x] != 'X') {
        if (map[y][x] != 'O')
            mvprintw(y, x, " ");
        mvprintw(y + 1, x, "P");
        player.y += 1;
    }
    if (map[y + 1][x] == 'X') {
        player = check_box_down(x, y + 1, map, player);
    }
    return player;
}

pos_t check_move_right(pos_t player, char **map)
{
    int x = player.x;
    int y = player.y;

    if (map[y][x + 1] != '#' && map[y][x + 1] != 'X') {
        if (map[y][x] != 'O')
            mvprintw(y, x, " ");
        mvprintw(y, x + 1, "P");
        player.x += 1;
    }
    if (map[y][x + 1] == 'X') {
        player = check_box_right(x + 1, y, map, player);
    }
    return player;
}

pos_t check_move_left(pos_t player, char **map)
{
    int x = player.x;
    int y = player.y;

    if (map[y][x - 1] != '#' && map[y][x - 1] != 'X') {
        if (map[y][x] != 'O')
            mvprintw(y, x, " ");
        mvprintw(y, x - 1, "P");
        player.x -= 1;
    }
    if (map[y][x - 1] == 'X') {
        player = check_box_left(x - 1, y, map, player);
    }
    return player;
}
