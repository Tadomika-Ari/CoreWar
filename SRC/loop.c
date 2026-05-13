/*
** EPITECH PROJECT, 2026
** CoreWar
** File description:
** loop
*/

#include "../include/robotfactorie.h"

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
    if (alive <= 1) {
        if (winner != NULL)
            my_printf("The player %d(%s) has won.\n",
                winner->name_champ, winner->file_champ);
        else
            my_printf("No champion alive.\n");
        return 1;
    }
    return 0;
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

    see_struct(list_champ);
    set_champ_dead(list_champ, core, 0);
    for (int cycle = 1; cycle_to_die >= 0; cycle++) {
        if (check_is_dead(life, list_champ, core) == 1) {
            printf("%d", cycle);
            return 0;
        }
        set_champ_dead(list_champ, core, 1);
        cycle_to_die = cycle_to_die - delta;
    }
    check_win(core, list_champ);
    return 0;
}
