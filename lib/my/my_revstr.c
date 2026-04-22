/*
** EPITECH PROJECT, 2025
** my_revstr
** File description:
** task03
*/
#include <stdio.h>
#include "my.h"

char *my_revstr(char *str)
{
    int i = 0;
    char temp;
    int der = my_strlen(str);

    while (i < (der - 1) / 2) {
        temp = str[i];
        str[i] = str[der - 1 - i];
        str[der - 1 - i] = temp;
        i++;
    }
    return str;
}
