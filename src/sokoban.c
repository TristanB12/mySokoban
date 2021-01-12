/*
** EPITECH PROJECT, 2019
** sokoban
** File description:
** gestion of all sokoban function
*/

#include "sokoban.h"
#include <curses.h>
#include "struct.h"
#include <stdlib.h>

pos_t get_player_position(char **map, pos_t player)
{
    int x = 0;
    int y = 0;

    while (map[y] != NULL) {
        x = 0;
        while (map[y][x] != '\0') {
            if (map[y][x] == 'P') {
                player.x = x;
                player.y = y;
            }
            x++;
        }
        y++;
    }
    return player;
}

pos_t manage_arrows(int key, pos_t player, char **map)
{
    if (key == KEY_UP)
        player = check_move_up(player, map);
    if (key == KEY_DOWN)
        player = check_move_down(player, map);
    else if (key == KEY_RIGHT)
        player = check_move_right(player, map);
    if (key == KEY_LEFT)
        player = check_move_left(player, map);
    return player;
}

void init_all(char **map)
{
    clear();
    initscr();
    print_tab(map);
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
}

int sokoban(char **map, char *str)
{
    int key = 0;
    int nb_storage = 0;
    char **tmp = put_str_in_tab(str);
    pos_t player = get_player_position(map, player);
    storage_t *storage = get_storage_position(map, &nb_storage);

    init_all(map);
    while (check_win(map, storage, nb_storage) == 1) {
        key = getch();
        if (key == 32) {
            sokoban(tmp, str);
            return 42;
        }
        player = manage_arrows(key, player, map);
        print_storage_location(storage, player, map);
        if (check_loss(map) == 84)
            return 1;
        refresh();
    }
    endwin();
    return 0;
}