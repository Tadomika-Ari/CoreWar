/*
** EPITECH PROJECT, 2026
** CoreWar
** File description:
** create_champion
*/

#include "../include/robotfactorie.h"

void init_last(champ_t *tmp)
{
    for (int i = 0; i < REG_NUMBER; i++)
        tmp->registers[i] = 0;
    tmp->pc = 0;
    tmp->carry = 0;
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
    tmp->name_champ = 0;
    tmp->size = 0;
    tmp->position = 0;
    tmp->pc = 0;
    tmp->carry = 0;
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
    tmp->pc = tmp->position;
    tmp->registers[0] = tmp->name_champ;
    return tmp;
}
