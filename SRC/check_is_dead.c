/*
** EPITECH PROJECT, 2026
** CoreWar
** File description:
** check_is_dead
*/

#include "../include/robotfactorie.h"

int delibiration(int alive, champ_t *winner)
{
    int no_champ_printed = 0;

    if (alive > 1)
        return 0;
    if (alive == 1) {
        my_printf("The player %d(%s) has won.\n",
            winner->name_champ, winner->file_champ);
        return 1;
    }
    if (alive == 0) {
        if (no_champ_printed == 0) {
            my_printf("No champion alive.\n");
            no_champ_printed = 1;
        }
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
        if (champ->is_alive == 1) {
            alive++;
            winner = champ;
        }
    }
    return delibiration(alive, winner);
}
