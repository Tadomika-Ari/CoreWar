/*
** EPITECH PROJECT, 2025
** my_molloc
** File description:
** my_molloc
*/

#include "../my.h"

void *my_malloc(size_t size)
{
    void *ptr = malloc(size);

    if (ptr == NULL) {
        my_printf("error malloc");
        return NULL;
    }
    return ptr;
}

void my_free(void *ptr)
{
    if (ptr != NULL)
        free(ptr);
    return;
}
