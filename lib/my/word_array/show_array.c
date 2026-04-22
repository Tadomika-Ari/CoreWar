/*
** EPITECH PROJECT, 2025
** show array
** File description:
** show_array
*/

#include "../../../include/my.h"
#include <stdlib.h>

int my_show_word_array(char **tab)
{
    for (int ch = 0; tab[ch] != NULL; ch++) {
        my_putstr(tab[ch]);
        my_putchar('\n');
    }
    return 0;
}
