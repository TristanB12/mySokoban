/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** header of pushswap
*/

#include "struct.h"

#ifndef SOKOBAN_H__
#define SOKOBAN_H__

int check_readable(char *str);
int check_loss(char **map);
int check_win(char **map, storage_t *storage, int nbr_storage);
storage_t *get_storage_position(char **map, int *nb);
void print_storage_location(storage_t *storage, pos_t player, char **map);
pos_t check_box_up(int x, int y, char **map, pos_t player);
pos_t check_box_down(int x, int y, char **map, pos_t player);
pos_t check_box_right(int x, int y, char **map, pos_t player);
pos_t check_box_left(int x, int y, char **map, pos_t player);
pos_t check_move_up(pos_t player, char **map);
pos_t check_move_down(pos_t player, char **map);
pos_t  check_move_right(pos_t player, char **map);
pos_t check_move_left(pos_t player, char **map);
int sokoban(char **map, char *str);
int errors(char *str);
char **malloc_tab(int nb_l, int nb_c);
int get_nb_char(char *str);
int get_nb_line(char *str);
char **put_str_in_tab(char *str);
void print_tab(char **tab);

#endif
