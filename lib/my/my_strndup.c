/*
** EPITECH PROJECT, 2025
** my_strndup
** File description:
** duplicates a string with a given length
*/

#include "my.h"
#include <stdlib.h>

char *my_strndup(char const *str, int n)
{
    char *copy = malloc(sizeof(char) * (n + 1));
    int i = 0;

    if (copy == NULL)
        return NULL;
    for (; i < n && str[i] != '\0'; i++)
        copy[i] = str[i];
    copy[i] = '\0';
    return copy;
}
