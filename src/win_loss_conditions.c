/*
** EPITECH PROJECT, 2019
** win loss conditions
** File description:
** check if the player won or lost the game
*/

#include "struct.h"
#include <stddef.h>
#include <curses.h>

int is_same_pos(int x, int y, storage_t *storage)
{
    storage_t *tmp = storage;

    while (tmp != NULL) {
        if (x == tmp->x && y == tmp->y) {
            mvprintw(y, x, "X");
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

int check_win(char **map, storage_t *storage, int nbr_storage)
{
    int x = 0;
    int y = 0;
    int count = 0;

    while (map[y] != NULL) {
        x = 0;
        while (map[y][x] != '\0') {
            if (map[y][x] == 'X') {
                count += is_same_pos(x, y, storage);
            }
            x++;
        }
        y++;
    }
    if (count == nbr_storage)
        return 0;
    return 1;
}

int can_move_x(int x, int y, char **map)
{
    int count = 0;

    if (map[y][x - 1] == '#' || map[y][x - 1] == 'X')
        count++;
    if (map[y][x + 1] == '#' || map[y][x + 1] == 'X')
        count++;
    return count;
}

int can_move_y(int x, int y, char **map)
{
    int count = 0;

    if (map[y - 1][x] == '#' || map[y - 1][x] == 'X')
        count++;
    if (map[y + 1][x] == '#' || map[y + 1][x] == 'X')
        count++;
    return count;
}

int check_loss(char **map)
{
    int x = 0;
    int y = 0;

    while (map[y] != NULL) {
        x = 0;
        while (map[y][x] != '\0') {
            if (map[y][x] == 'X' &&
                (can_move_x(x, y, map) == 0 ||
                can_move_y(x, y, map) == 0)) {
                    return 0;
            }
            x++;
        }
        y++;
    }
    return 84;
}