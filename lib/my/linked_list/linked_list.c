/*
** EPITECH PROJECT, 2025
** linked_list
** File description:
** linked_list
*/

#include "../../../include/my.h"

void push_to_front(ll_t **begin, void *data)
{
    ll_t *new = malloc(sizeof(ll_t));

    if (new == NULL)
        return;
    new->data = data;
    new->next = *begin;
    *begin = new;
}
