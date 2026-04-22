/*
** EPITECH PROJECT, 2026
** push to back
** File description:
** push_to_back
*/

#include "../../../include/my.h"

void push_to_back(ll_t **begin, void *data)
{
    ll_t *new = NULL;
    ll_t *current = NULL;

    if (begin == NULL)
        return;
    new = malloc(sizeof(ll_t));
    if (new == NULL)
        return;
    new->data = data;
    new->next = NULL;
    if (*begin == NULL) {
        *begin = new;
        return;
    }
    current = *begin;
    while (current->next != NULL)
        current = current->next;
    current->next = new;
}
