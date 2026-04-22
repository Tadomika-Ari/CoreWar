/*
** EPITECH PROJECT, 2025
** strcat
** File description:
** strcat
*/

#include "../include/my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int index = 0;
    int len = my_strlen(dest);

    if (!dest || !src || nb <= 0)
        return dest;
    for (; src[index] != '\0' && index < nb; index++) {
        dest[index + len] = src[index];
    }
    dest[index + len] = '\0';
    return dest;
}
