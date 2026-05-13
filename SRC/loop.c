/*
** EPITECH PROJECT, 2026
** CoreWar
** File description:
** loop
*/

#include "../include/robotfactorie.h"

int delibiration(int alive, champ_t *winner)
{
    if (alive > 1)
        return 0;
    if (alive == 1) {
        my_printf("The player %d(%s) has won.\n",
            winner->name_champ, winner->file_champ);
        return 1;
    }
    if (alive == 0) {
        my_printf("No champion alive.\n");
        return 1;
    }
    return 1;
}

int check_is_dead(int life, ll_t *list_champ, coreware_t *core)
{
    champ_t *champ = NULL;
    champ_t *winner = NULL;
    int alive = 0;

    for (ll_t *tmp = list_champ; tmp; tmp = tmp->next) {
        champ = tmp->data;
        if (champ->is_active == 1) {
            alive++;
            winner = champ;
        }
    }
    return delibiration(alive, winner);
}

int check_win(coreware_t *core, ll_t *list_champ)
{
    return check_is_dead(0, list_champ, core);
}

int loop(coreware_t *core, ll_t *list_champ)
{
    int life = 0;
    int delta = CYCLE_DELTA;
    int cycle_to_die = core->nb_cyrcle_to_die;
    int cylce = 0;

    see_struct(list_champ);
    set_champ_dead(list_champ, core, 0);
    while (cycle_to_die >= 0 && check_is_dead(life, list_champ, core) == 0) {
        for (cylce = 1; cylce < cycle_to_die; cylce++) {
        }
        cycle_to_die -= delta;
    }
    if (cycle_to_die < 0) {
        if (check_is_dead(life, list_champ, core) == 0)
            my_printf("No winner.\n");
    }
    return 0;
}
