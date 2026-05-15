/*
** EPITECH PROJECT, 2026
** CoreWar
** File description:
** loop
*/

#include "../include/robotfactorie.h"

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

static void setup_arena(coreware_t *core, ll_t *list_champ, uint8_t *arena)
{
    if (core->dump_cycle == -1)
        print_arena(arena);
    see_struct(list_champ);
    scan_map(core, list_champ, arena);
}

static int run_cycle_to_die(ll_t *list_champ, uint8_t *arena,
    coreware_t *core, int cycle_to_die)
{
    int i = 0;

    while (i < cycle_to_die) {
        increment_cycles(list_champ);
        instruction(core, list_champ, arena);
        i++;
    }
    return i;
}

static int dump_requested_cycle(coreware_t *core, int cycle_count,
    uint8_t *arena, ll_t *list_champ)
{
    if (core->dump_cycle == -1 || cycle_count < core->dump_cycle)
        return 0;
    dump(core->dump_cycle, arena, list_champ);
    return 1;
}

static int dump_last_cycle_if_needed(coreware_t *core, int cycle_count,
    uint8_t *arena, ll_t *list_champ)
{
    if (core->dump_cycle == -1 || cycle_count >= core->dump_cycle)
        return 0;
    dump(cycle_count, arena, list_champ);
    return 1;
}

static int finish_cycle_block(coreware_t *core, ll_t *list_champ,
    uint8_t *arena, cycles_t *cycles)
{
    if (dump_requested_cycle(core, *cycles->count, arena, list_champ))
        return 1;
    kill_inactive_champs(list_champ, *cycles->to_die);
    if (check_is_dead(0, list_champ, core) != 0) {
        dump_last_cycle_if_needed(core, *cycles->count, arena, list_champ);
        return 1;
    }
    *cycles->to_die -= CYCLE_DELTA;
    return 0;
}

static int run_main_loop(coreware_t *core, ll_t *list_champ,
    uint8_t *arena, cycles_t *cycles)
{
    while (*cycles->to_die > 0) {
        *cycles->count += run_cycle_to_die(list_champ, arena,
            core, *cycles->to_die);
        if (finish_cycle_block(core, list_champ, arena, cycles))
            return 0;
    }
    dump_last_cycle_if_needed(core, *cycles->count, arena, list_champ);
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
