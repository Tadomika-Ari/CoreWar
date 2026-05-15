/*
** EPITECH PROJECT, 2026
** CoreWar
** File description:
** loop
*/

#include "../include/robotfactorie.h"

int check_is_alive(coreware_t *core, ll_t *list_champ)
{
    (void)core;
    (void)list_champ;
    return 0;
}

int after_cycle(coreware_t *core, ll_t *list_champ, int life)
{
    check_is_alive(core, list_champ);
    if (check_is_dead(life, list_champ, core) != 0)
        return 1;
    return 0;
}

static int increment_cycles(ll_t *list_champ)
{
    ll_t *tmp;
    champ_t *champ;

    for (tmp = list_champ; tmp; tmp = tmp->next) {
        champ = (champ_t *)tmp->data;
        if (champ->is_alive == 1)
            champ->cycles_without_live++;
    }
    return 0;
}

static int kill_inactive_champs(ll_t *list_champ, int cycle_to_die)
{
    ll_t *tmp;
    champ_t *champ;

    for (tmp = list_champ; tmp; tmp = tmp->next) {
        champ = (champ_t *)tmp->data;
        if (champ->cycles_without_live >= cycle_to_die)
            champ->is_alive = 0;
    }
    return 0;
}

static int handle_cycles(coreware_t *core, ll_t *list_champ,
    uint8_t *arena, cycles_t *cycles)
{
    int i;

    i = 0;
    while (i < *cycles->to_die) {
        (*cycles->count)++;
        increment_cycles(list_champ);
        instruction(core, list_champ, arena);
        if (core->dump_cycle != -1 && *cycles->count == core->dump_cycle)
            return 1;
        i++;
    }
    return 0;
}

static void setup_arena(coreware_t *core, ll_t *list_champ, uint8_t *arena)
{
    if (core->dump_cycle == -1)
        print_arena(arena);
    see_struct(list_champ);
    scan_map(core, list_champ, arena);
}

static int run_main_loop(coreware_t *core, ll_t *list_champ,
    uint8_t *arena, cycles_t *cycles)
{
    while (*cycles->to_die > 0) {
        if (handle_cycles(core, list_champ, arena, cycles)) {
            dump(*cycles->count, arena, list_champ);
            return 0;
        }
        kill_inactive_champs(list_champ, *cycles->to_die);
        if (check_is_dead(0, list_champ, core) != 0)
            break;
        *cycles->to_die -= CYCLE_DELTA;
    }
    return 0;
}

int loop(coreware_t *core, ll_t *list_champ, uint8_t *arena)
{
    cycles_t cycles;
    int cycle_count;
    int cycle_to_die;

    cycle_count = 0;
    cycle_to_die = core->nb_cyrcle_to_die;
    cycles.count = &cycle_count;
    cycles.to_die = &cycle_to_die;
    setup_arena(core, list_champ, arena);
    return run_main_loop(core, list_champ, arena, &cycles);
}
