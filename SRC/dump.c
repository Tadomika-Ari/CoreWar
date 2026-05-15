/*
** EPITECH PROJECT, 2026
** dump
** File description:
** dump
*/

#include "../include/robotfactorie.h"

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

static void print_registers(champ_t *champ)
{
    for (int i = 0; i < REG_NUMBER; i++) {
        my_printf("r%d", i + 1);
        if (i + 1 < 10)
            my_putchar(' ');
        my_printf(": ");
        print_hex_padded((unsigned int)champ->registers[i], 8);
        if (i % 6 != 5 && i != REG_NUMBER - 1)
            my_putchar(' ');
        if (i % 6 == 5 || i == REG_NUMBER - 1)
            my_putchar('\n');
    }
}

static void print_champion_state(ll_t *list_champ)
{
    champ_t *champ = NULL;

    for (ll_t *tmp = list_champ; tmp; tmp = tmp->next) {
        champ = tmp->data;
        my_printf("%s(%d): %s\n", champ->file_champ,
            champ->name_champ, champ->is_alive ? "alive" : "dead");
        print_registers(champ);
        my_printf("PC : ");
        print_hex_padded((unsigned int)champ->pc, 8);
        my_printf(" carry: %d\n", champ->carry);
    }
}

int dump(int cycle, uint8_t *arena, ll_t *list_champ)
{
    my_printf("Cycle: %d\n", cycle);
    my_printf("Registers:\n");
    print_champion_state(list_champ);
    my_printf("Memory:\n");
    print_arena(arena);
    return 0;
}
