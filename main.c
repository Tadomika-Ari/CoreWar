/*
** EPITECH PROJECT, 2026
** main
** File description:
** robotfactori
*/

#include "include/robotfactorie.h"
#include <stdint.h>

void check_pos(champ_t *tmp, int *i, char **av)
{
    if (av[*i] != NULL && av[*i][0] == '-' && av[*i][1] == 'a') {
        if (av[*i + 1] != NULL) {
            tmp->position = my_getnbr(av[*i + 1]);
            *i = *i + 2;
        }
    }
}

void see_struct(ll_t *list_champ)
{
    champ_t *tmp = NULL;
    ll_t *next = NULL;

    while (list_champ != NULL) {
        next = list_champ->next;
        tmp = list_champ->data;
        my_printf("NAME : %s\n", tmp->file_champ);
        my_printf("ID : %d\n", tmp->name_champ);
        list_champ = next;
    }
}

int init_struct(coreware_t *core)
{
    core->nb_champion = 0;
    core->nb_cyrcle_to_die = CYCLE_TO_DIE;
    return 0;
}

int free_all(coreware_t *core, uint8_t *arena, ll_t *list_champ)
{
    my_free_list(&list_champ);
    free(arena);
    free(core);
    return 0;
}

int main(int ac, char **av)
{
    uint8_t *arena = create_arena();
    coreware_t *core = malloc(sizeof(coreware_t));
    ll_t *list_champ = NULL;
    champ_t *tmp = NULL;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return help();
    init_struct(core);
    for (int i = 1; av[i] != NULL;) {
        tmp = init_champ(av, &i);
        if (tmp == NULL) {
            return my_puterror("error  init_champ\n", 84);
        }
        push_to_back(&list_champ, tmp);
        core->nb_champion++;
    }
    if (write_in_arena(arena, core->nb_champion, av) == 84)
        return my_puterror("error write in arena\n", 84);
    loop(core, list_champ, arena);
    return free_all(core, arena, list_champ);
}
