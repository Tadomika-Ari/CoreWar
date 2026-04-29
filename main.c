/*
** EPITECH PROJECT, 2026
** main
** File description:
** robotfactori
*/

#include "include/robotfactorie.h"
#include <stdint.h>

int main(int ac, char **av)
{
    uint8_t *arena = create_arena();

    free(arena);
    return OK;
}
