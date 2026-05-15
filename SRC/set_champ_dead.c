/*
** EPITECH PROJECT, 2026
** CoreWar
** File description:
** set_champ_dead
*/

#include "../include/robotfactorie.h"

int set_champ_dead(ll_t *list_champ, coreware_t *core, int champ_target)
{
    ll_t *tmp = list_champ;
    champ_t *champ = NULL;

    if (champ_target > core->nb_champion) {
        return 84;
    }
    for (int i = 0; i != champ_target; i++) {
        if (tmp == NULL)
            return 84;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return 84;
    champ = tmp->data;
    champ->is_alive = 0;
    return 0;
}
