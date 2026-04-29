/*
** EPITECH PROJECT, 2026
** CoreWar
** File description:
** arena
*/

#include "../include/robotfactorie.h"

uint8_t *create_arena(void)
{
    uint8_t *arena = malloc(MEM_SIZE);

    for (int i = 0; i < MEM_SIZE; i++)
        arena[i] = 0;
    return arena;
}
