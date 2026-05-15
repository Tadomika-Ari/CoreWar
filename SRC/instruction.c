/*
** EPITECH PROJECT, 2026
** CoreWar
** File description:
** instruction
*/

#include "../include/robotfactorie.h"

static int arg_size_from_code(int type_code, int opcode)
{
    if (type_code == 1)
        return 1;
    if (type_code == 2)
        return (opcode == 9 || opcode == 10 || opcode == 11 || opcode == 12
            || opcode == 14 || opcode == 15) ? IND_SIZE : DIR_SIZE;
    if (type_code == 3)
        return IND_SIZE;
    return 0;
}

static int has_coding_byte(int opcode)
{
    return !(opcode == 1 || opcode == 9 || opcode == 12 || opcode == 15);
}

static int calc_step(uint8_t *arena, int pos, int opcode)
{
    int arg_sizes = 0;
    int coding = 0;
    int type_code = 0;

    if (has_coding_byte(opcode)) {
        coding = arena[(pos + 1) % MEM_SIZE];
        for (int a = 0; a < op_tab[opcode].nbr_args; a++) {
            type_code = (coding >> (6 - (2 * a))) & 0x3;
            arg_sizes += arg_size_from_code(type_code, opcode);
        }
        return 1 + 1 + arg_sizes;
    }
    return 1 + ((opcode == 9 || opcode == 10 || opcode == 11 || opcode == 12
            || opcode == 14 || opcode == 15) ? IND_SIZE : DIR_SIZE);
}

static int is_valid_opcode(int opcode)
{
    return opcode >= 1 && opcode <= 16 && op_tab[opcode].mnemonique != NULL;
}

static void execute_live(champ_t *champ)
{
    champ->is_alive = 1;
    champ->cycles_without_live = 0;
}

static void execute_instruction(champ_t *champ, uint8_t *arena, int opcode)
{
    if (opcode == 1) {
        execute_live(champ);
    }
}

int instruction(coreware_t *core, ll_t *list_champ, uint8_t *arena)
{
    champ_t *champ = NULL;
    int opcode = 0;
    int step = 1;

    for (ll_t *tmp = list_champ; tmp; tmp = tmp->next) {
        champ = tmp->data;
        if (champ->is_alive == 0)
            continue;
        opcode = arena[champ->pc % MEM_SIZE];
        if (is_valid_opcode(opcode)) {
            execute_instruction(champ, arena, opcode);
            if (opcode == 1)
                core->total_live++;
            step = calc_step(arena, champ->pc, opcode);
            champ->pc = (champ->pc + step) % MEM_SIZE;
        } else {
            champ->pc = (champ->pc + 1) % MEM_SIZE;
        }
    }
    return 0;
}
