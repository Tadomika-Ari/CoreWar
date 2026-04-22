/*
** EPITECH PROJECT, 2025
** len_list
** File description:
** len_list
*/

#include "../my.h"


int len_list(ll_t **list)
{
    int len = 0;
    ll_t *current = *list;

    while (current != NULL) {
        len++;
        current = current->next;
    }
    return len;
}
