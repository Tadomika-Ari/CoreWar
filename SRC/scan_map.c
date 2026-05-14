/*
** EPITECH PROJECT, 2026
** CoreWar
** File description:
** scan_map
*/

#include "../include/robotfactorie.h"

void scan_map(coreware_t *core, ll_t *list_champ, uint8_t *arena)
{
    int found = 0;
    int opcode = 0;

    if (arena == NULL)
        return;
    my_printf("[SCAN] looking for instructions in arena\n");
    for (int i = 0; i < MEM_SIZE; i++) {
        opcode = arena[i];
        if (opcode < 1 || opcode > 16)
            continue;
        if (op_tab[opcode].mnemonique == NULL)
            continue;
        my_printf("[SCAN] pos=%d opcode=%d instr=%s cycles=%d\n",
            i, opcode, op_tab[opcode].mnemonique, op_tab[opcode].nbr_cycles);
        found++;
    }
    if (found == 0)
        my_printf("[SCAN] no opcode found\n");
    return;
}
