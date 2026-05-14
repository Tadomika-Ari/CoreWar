/*
** EPITECH PROJECT, 2026
** print_arena
** File description:
** Dump arena contents for inspection
*/

#include "../include/robotfactorie.h"
#include <ctype.h>
#include <stdio.h>

void print_arena(uint8_t *arena)
{
    unsigned char c = '\0';

    if (arena == NULL)
        return;
    for (int off = 0; off < MEM_SIZE; off += 16) {
        printf("%04x : ", (unsigned int)off);
        for (int i = 0; i < 16 && off + i < MEM_SIZE; i++)
            printf("%02x ", (unsigned int)arena[off + i]);
        printf("| ");
        for (int i = 0; i < 16 && off + i < MEM_SIZE; i++) {
            c = arena[off + i];
            printf("%c", isprint(c) ? c : '.');
        }
        printf("\n");
    }
}
