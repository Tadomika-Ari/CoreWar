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

int loop(coreware_t *core, ll_t *list_champ, uint8_t *arena)
{
    int life = 0;
    int delta = CYCLE_DELTA;
    int cycle_to_die = core->nb_cyrcle_to_die;

    print_arena(arena);
    see_struct(list_champ);
    scan_map(core, list_champ, arena);
    while (cycle_to_die >= 0) {
        for (int cylce = 1; cylce < cycle_to_die; cylce++) {
            instruction(core, list_champ, arena);
        }
        if (after_cycle(core, list_champ, life) == 1) {
            break;
        }
        cycle_to_die -= delta;
    }
    return 0;
}
