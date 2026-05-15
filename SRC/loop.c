/*
** EPITECH PROJECT, 2026
** CoreWar
** File description:
** loop
*/

#include "../include/robotfactorie.h"

int check_is_alive(coreware_t *core, ll_t *list_champ)
{
    champ_t *champ = NULL;

    for (ll_t *tmp = list_champ; tmp; tmp = tmp->next) {
        champ = tmp->data;
        if (champ->is_alive == 1) {
            my_printf("Champion %d(%s) is alive\n", champ->name_champ,
                champ->file_champ);
        }
        if (champ->is_alive == 0) {
            my_printf("Champion %d(%s) is dead\n", champ->name_champ,
                champ->file_champ);
        }
    }
    return 0;
}

int after_cycle(coreware_t *core, ll_t *list_champ, int life)
{
    check_is_alive(core, list_champ);
    if (check_is_dead(life, list_champ, core) != 0)
        return 1;
    return 0;
}

static int run_cycle_phase(coreware_t *core, ll_t *list_champ,
    uint8_t *arena, int *state)
{
    for (int current = 1; current < state[0]; current++) {
        instruction(core, list_champ, arena);
        state[1] = state[1] + 1;
        if (core->dump_cycle >= 0 && state[1] == core->dump_cycle) {
            dump(state[1], arena, list_champ);
            return 1;
        }
    }
    return 0;
}

int loop(coreware_t *core, ll_t *list_champ, uint8_t *arena)
{
    int life = 0;
    int delta = CYCLE_DELTA;
    int state[2] = {core->nb_cyrcle_to_die, 0};

    if (core->dump_cycle < 0) {
        print_arena(arena);
        see_struct(list_champ);
        scan_map(core, list_champ, arena);
    }
    if (core->dump_cycle == 0)
        return dump(0, arena, list_champ);
    while (state[0] >= 0) {
        if (run_cycle_phase(core, list_champ, arena, state) == 1)
            return 0;
        if (after_cycle(core, list_champ, life) == 1)
            break;
        state[0] -= delta;
    }
    return 0;
}
