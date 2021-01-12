/*
** EPITECH PROJECT, 2019
** tab function
** File description:
** all function linked to the map tab
*/

#include "stdlib.h"
#include "my.h"
#include <curses.h>

char **malloc_tab(int nb_l, int nb_c)
{
    char **tab = NULL;
    int i = 0;

    tab = malloc(sizeof(char *) * (nb_l + 2));
    while (nb_l > i) {
        tab[i] = malloc(sizeof(char) * (nb_c + 2));
        i++;
    }
    return tab;
}

    void print_tab(char **tab)
    {
        int y = 0;
        int x = 0;

        while (tab[y] != NULL) {
            x = 0;
            while (tab[y][x] != '\0') {
                printw("%c", tab[y][x]);
                x++;
            }
            printw("\n");
            y++;
        }
    }

int get_nb_char(char *str)
{
    int nb_char = 0;
    int i = 0;

    while (str[i] != '\n') {
        nb_char++;
        i++;
    }
    return nb_char;
}

int get_nb_line(char *str)
{
    int nb_line = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n')
            nb_line++;
        i++;
    }
    nb_line++;
    return nb_line;
}

char **put_str_in_tab(char *str)
{
    char **tab = NULL;
    int x = 0;
    int y = 0;
    int i = 0;

    tab = malloc(sizeof(char *) * (get_nb_line(str)) + 1);
    while (str[i] != '\0') {
        tab[y] = malloc(sizeof(char) * (get_nb_char(&str[i]) + 1));
        while (str[i] && str[i] != '\n') {
            tab[y][x] = str[i];
            i++;
            x++;
        }
        tab[y][x] = '\0';
        y++;
        if (str[i] && str[i] == '\n')
        i++;
        x = 0;
    }
    tab[y] = NULL;
    return tab;
}
