/*
** EPITECH PROJECT, 2025
** array_len
** File description:
** array_len
*/

#include "../../../include/my.h"

int array_len(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        i++;
    }
    return i;
}
