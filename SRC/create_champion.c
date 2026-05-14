/*
** EPITECH PROJECT, 2026
** CoreWar
** File description:
** create_champion
*/

#include "../include/robotfactorie.h"

void init_last(champ_t *tmp)
{
    tmp->is_alive = 1;
    tmp->coldown = 0;
}

champ_t *init_champ(char **av, int *i)
{
    champ_t *tmp = malloc(sizeof(champ_t));

    if (av[*i] == NULL || av[*i][0] != '-' || av[*i][1] != 'n') {
        my_printf("No nb\n");
        free(tmp);
        return NULL;
    }
    tmp->name_champ = my_getnbr(av[*i + 1]);
    *i = *i + 2;
    check_pos(tmp, i, av);
    if (av[*i] == NULL || av[*i][0] == '-') {
        my_printf("no file\n");
        free(tmp);
        return NULL;
    }
    tmp->file_champ = av[*i];
    *i = *i + 1;
    init_last(tmp);
    return tmp;
}
