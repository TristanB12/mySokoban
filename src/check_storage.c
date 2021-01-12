/*
** EPITECH PROJECT, 2019
** check_storage
** File description:
** functions to check if storage is full
*/

#include "sokoban.h"
#include "struct.h"
#include "stddef.h"
#include "ncurses.h"
#include <stdlib.h>

storage_t *create_list_storage(int x, int y, storage_t *list)
{
    storage_t *element;
    storage_t *tmp = list;

    while (tmp != NULL && tmp->next != NULL) {
        tmp = tmp->next;
    }
    element = malloc(sizeof(storage_t));
    element->x = x;
    element->y = y;
    element->next = NULL;
    if (tmp)
        tmp->next = element;
    else
        list = element;

    return list;
}

storage_t *get_storage_position(char **map, int *nbr)
{
    int x = 0;
    int y = 0;
    storage_t *storage = NULL;

    while (map[y] != NULL) {
        x = 0;
        while (map[y][x] != '\0') {
            if (map[y][x] == 'O') {
            nbr[0]++;
                storage = create_list_storage(x, y, storage);
            }
            x++;
        }
        y++;
    }
    return storage;
}

char **delete_player(char **map)
{
    int x = 0;
    int y = 0;

    while (map[y] != NULL) {
        x = 0;
        while (map[y][x] != '\0') {
            if (map[y][x] == 'P')
                map[y][x] = ' ';
            x++;
        }
        y++;
    }
    return map;
}

void print_storage_location(storage_t *storage, pos_t player, char **map)
{
    storage_t *tmp = storage;

    map = delete_player(map);
    map[player.y][player.x] = 'P';
    while (tmp != NULL) {
        if (map[tmp->y][tmp->x] != 'P' && map[tmp->y][tmp->x] != 'X')
            mvprintw(tmp->y, tmp->x, "O");
        tmp = tmp->next;
    }
}