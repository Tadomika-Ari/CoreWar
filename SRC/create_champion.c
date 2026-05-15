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

static int is_champ_flag(char *arg)
{
    if (arg == NULL)
        return 0;
    if (arg[0] != '-' || arg[1] != 'n')
        return 0;
    return 1;
}

static int set_champ_info(champ_t *tmp, char **av, int *i)
{
    if (av[*i + 1] == NULL)
        return my_puterror("No nb\n", 84);
    tmp->name_champ = my_getnbr(av[*i + 1]);
    *i += 2;
    check_pos(tmp, i, av);
    if (av[*i] == NULL || av[*i][0] == '-')
        return my_puterror("no file\n", 84);
    tmp->file_champ = av[*i];
    *i += 1;
    return 0;
}

static void finish_champ_init(champ_t *tmp)
{
    init_last(tmp);
    tmp->pc = tmp->position;
    tmp->registers[0] = tmp->name_champ;
}

champ_t *init_champ(char **av, int *i)
{
    champ_t *tmp = malloc(sizeof(champ_t));

    if (tmp == NULL)
        return NULL;
    if (is_champ_flag(av[*i]) == 0) {
        my_printf("No nb\n");
        free(tmp);
        return NULL;
    }
    tmp->name_champ = 0;
    tmp->size = 0;
    tmp->position = 0;
    tmp->pc = 0;
    tmp->carry = 0;
    if (set_champ_info(tmp, av, i) == 84) {
        free(tmp);
        return NULL;
    }
    finish_champ_init(tmp);
    return tmp;
}
