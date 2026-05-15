/*
** EPITECH PROJECT, 2026
** dump
** File description:
** dump
*/

#include "../include/robotfactorie.h"

static void print_registers(champ_t *champ)
{
    for (int i = 0; i < REG_NUMBER; i++) {
        printf("r%-2d: %08x", i + 1, (unsigned int)champ->registers[i]);
        if (i % 6 != 5 && i != REG_NUMBER - 1)
            printf(" ");
        if (i % 6 == 5 || i == REG_NUMBER - 1)
            printf("\n");
    }
}

static void print_champion_state(ll_t *list_champ)
{
    champ_t *champ = NULL;

    for (ll_t *tmp = list_champ; tmp; tmp = tmp->next) {
        champ = tmp->data;
        printf("%s(%d): %s\n", champ->file_champ,
            champ->name_champ, champ->is_alive ? "alive" : "dead");
        print_registers(champ);
        printf("PC : %08xcarry: %d\n", (unsigned int)champ->pc,
            champ->carry);
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