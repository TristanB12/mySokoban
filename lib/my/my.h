/*
** EPITECH PROJECT, 2019
** C Pool InfinAdd
** File description:
** Header file for libmy
*/

#include "struct.h"

#ifndef __DEF_MY__
#define __DEF_MY__

int flag_error(int ac, char **av);
int my_getnbr(char *str);
void my_putchar(char my_char);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_is_digit(char const my_char);
int is_left_paren(char const my_char);
int is_right_paren(char const my_char);
int is_paren(char const my_char);
int my_str_isnum(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_get_denominator(int const nb);
int my_intlen(int nb);
int my_strlen(char const *str);
int my_strlen_ns(char const *str);
int my_put_nbr(int nb);
int my_strnum_to_int(char *str);
char *my_strdup_ns(char const *str);
char *my_int_to_strnum(int nb);

#endif
