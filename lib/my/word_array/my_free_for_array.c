/*
** EPITECH PROJECT, 2025
** free array
** File description:
** my_free_fo_arry
*/

#include "../../../include/my.h"
#include <stdlib.h>

void my_free_array(char **tab)
{
    if (tab == NULL)
        return;
    for (int ele = 0; tab[ele] != NULL; ele++) {
        if (tab[ele] != NULL)
            free(tab[ele]);
    }
    free(tab);
}
