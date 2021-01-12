/*
** EPITECH PROJECT, 2019
** struct
** File description:
** struct for pushswap
*/

#ifndef STRUCT_H__
#define STRUCT_H__

typedef struct s_couple_x_y
{
    int x;
    int y;
}pos_t;

typedef struct s_storage_position
{
    int x;
    int y;
    struct s_storage_position *next;
}storage_t;

#endif
