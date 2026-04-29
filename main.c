/*
** EPITECH PROJECT, 2026
** main
** File description:
** robotfactori
*/

#include "include/robotfactorie.h"

int take_nb_chp(int ac, char **av)
{
    int nb = 0;

    for (int i = 0; av[i] != NULL; i++)
        if (my_strncmp(av[i], "-n", 2))
            nb++;
    return nb;
}

int init_core(coreware_t *core, int ac, char **av)
{
    core->nb_champion = take_nb_chp(ac, av);
    core->nb_cyrcle_to_die = 0;
}

int main(int ac, char **av)
{
    coreware_t *core = malloc(sizeof(coreware_t));
    ll_t *list_champ = NULL
    champ_t *tmp = NULL;

    init_champ()
    init_core(core, ac, av);
    my_printf("%s\n", core->nb_champion);
    free(core);
    return OK;
}
