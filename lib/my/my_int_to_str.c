/*
** EPITECH PROJECT, 2025
** my_int_to_str
** File description:
** my_int_to_str
*/

#include "my.h"

char *my_int_to_str(int nb)
{
    char buffer[12];
    int i = 0;
    char *str;

    if (nb == 0)
        return "0";
    while (nb > 0) {
        buffer[i] = '0' + (nb % 10);
        i++;
        nb /= 10;
    }
    buffer[i] = '\0';
    str = malloc(i + 1);
    for (int j = 0; j < i; j++) {
        str[j] = buffer[i - j - 1];
    }
    str[i] = '\0';
    return str;
}
