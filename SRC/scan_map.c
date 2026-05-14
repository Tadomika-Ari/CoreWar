/*
** EPITECH PROJECT, 2026
** CoreWar
** File description:
** scan_map
*/

#include "../include/robotfactorie.h"

static int has_coding_byte(int opcode)
{
    return !(opcode == 1 || opcode == 9 || opcode == 12 || opcode == 15);
}

static int is_index_dir(int opcode)
{
    return (opcode == 9 || opcode == 10 || opcode == 11 || opcode == 12
        || opcode == 14 || opcode == 15);
}

static int dir_size_for_opcode(int opcode)
{
    return is_index_dir(opcode) ? IND_SIZE : DIR_SIZE;
}

static int arg_size_from_code(int type_code, int opcode)
{
    if (type_code == 1)
        return 1;
    if (type_code == 2)
        return dir_size_for_opcode(opcode);
    if (type_code == 3)
        return IND_SIZE;
    return 0;
}

static int is_valid_opcode(int opcode)
{
    return opcode >= 1 && opcode <= 16 && op_tab[opcode].mnemonique != NULL;
}

static int step_with_coding(uint8_t *arena, int pos, int opcode)
{
    int arg_sizes = 0;
    int coding = arena[(pos + 1) % MEM_SIZE];
    int type_code = 0;

    for (int a = 0; a < op_tab[opcode].nbr_args; a++) {
        type_code = (coding >> (6 - (2 * a))) & 0x3;
        arg_sizes += arg_size_from_code(type_code, opcode);
    }
    return 1 + 1 + arg_sizes;
}

static int calc_step(uint8_t *arena, int pos, int opcode)
{
    if (has_coding_byte(opcode))
        return step_with_coding(arena, pos, opcode);
    return 1 + dir_size_for_opcode(opcode);
}

static int scan_one(uint8_t *arena, int pos, int *found)
{
    int opcode = arena[pos];

    if (!is_valid_opcode(opcode))
        return 1;
    my_printf("[SCAN] pos=%d opcode=%d instr=%s cycles=%d\n",
        pos, opcode, op_tab[opcode].mnemonique, op_tab[opcode].nbr_cycles);
    (*found)++;
    return calc_step(arena, pos, opcode);
}

void scan_map(coreware_t *core, ll_t *list_champ, uint8_t *arena)
{
    int found = 0;
    int step = 1;

    if (arena == NULL)
        return;
    my_printf("[SCAN] looking for instructions in arena\n");
    for (int i = 0; i < MEM_SIZE;) {
        step = scan_one(arena, i, &found);
        if (step <= 0)
            step = 1;
        i += step;
        continue;
    }
    if (found == 0)
        my_printf("[SCAN] no opcode found\n");
    return;
}
