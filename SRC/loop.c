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
        if (champ->is_active == 1) {
            my_printf("Champion %d(%s) is alive\n", champ->name_champ,
                champ->file_champ);
        }
        if (champ->is_active == 0) {
            my_printf("Champion %d(%s) is dead\n", champ->name_champ,
                champ->file_champ);
        }
    }
    return 0;
}

int loop(coreware_t *core, ll_t *list_champ)
{
    int life = 0;
    int delta = CYCLE_DELTA;
    int cycle_to_die = core->nb_cyrcle_to_die;

    see_struct(list_champ);
    set_champ_dead(list_champ, core, 1);
    while (cycle_to_die >= 0 && check_is_dead(life, list_champ, core) == 0) {
        for (int cylce = 1; cylce < cycle_to_die; cylce++) {
        }
        check_is_alive(core, list_champ);
        cycle_to_die -= delta;
    }
    if (cycle_to_die < 0) {
        if (check_is_dead(life, list_champ, core) == 0)
            my_printf("No winner.\n");
    }
    return 0;
}
