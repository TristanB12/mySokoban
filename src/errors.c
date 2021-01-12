/*
** EPITECH PROJECT, 2019
** errors
** File description:
** error management
*/

#include "my.h"
#include <fcntl.h>

int check_readable(char *str)
{
    int fd = 0;

    fd = open(str, O_RDONLY);
    if (fd <= 0)
        return 84;
    return 0;
}

int check_char(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] != '#' && str[i] != '\n' &&
            str[i] != ' ' && str[i] != 'X' &&
            str[i] != 'O' && str[i] != 'P') {
            my_putstr("This character is not allowed: ");
            my_putchar(str[i]);
            my_putchar('\n');
            return 84;
        }
        i++;
    }
    return 0;
}

int check_boxes_and_storage(char *str)
{
    int count_b = 0;
    int count_s = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == 'O')
            count_s++;
        if (str[i] == 'X')
            count_b++;
        i++;
    }
    if (count_b != count_s) {
        my_putstr("There are not the same number of boxe and storage\n");
        return 84;
    }
    return 0;
}

int errors(char *str)
{
    int err = 0;

    err += check_char(str);
    err += check_boxes_and_storage(str);
    return err;
}
