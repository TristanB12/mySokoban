/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** Returns the number of characters in a string.
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i = i + 1;
    return (i);
}
