/*
** EPITECH PROJECT, 2026
** print_arena
** File description:
** Dump arena contents for inspection
*/

#include "../include/robotfactorie.h"
#include <ctype.h>

static void print_hex_padded(unsigned int value, int width)
{
    const char *digits = "0123456789abcdef";
    char buffer[8];

    for (int i = width - 1; i >= 0; i--) {
        buffer[i] = digits[value % 16];
        value /= 16;
    }
    for (int i = 0; i < width; i++)
        my_putchar(buffer[i]);
}

void print_arena(uint8_t *arena)
{
    unsigned char c = '\0';

    if (arena == NULL)
        return;
    for (int off = 0; off < MEM_SIZE; off += 16) {
        print_hex_padded((unsigned int)off, 4);
        my_printf(" : ");
        for (int i = 0; i < 16 && off + i < MEM_SIZE; i++) {
            print_hex_padded((unsigned int)arena[off + i], 2);
            my_putchar(' ');
        }
        my_printf("| ");
        for (int i = 0; i < 16 && off + i < MEM_SIZE; i++) {
            c = arena[off + i];
            my_putchar(isprint(c) ? c : '.');
        }
        my_putchar('\n');
    }
}
