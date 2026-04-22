/*
** EPITECH PROJECT, 2025
** my_free_list
** File description:
** my_free_list
*/

#include "../my.h"

void my_free_list(ll_t **list)
{
    ll_t *current;
    ll_t *prev = NULL;

    if (list == NULL || *list == NULL)
        return;
    current = *list;
    while (current != NULL) {
        if (current->data != NULL)
            free(current->data);
        prev = current;
        current = current->next;
        free(prev);
    }
    *list = NULL;
}
