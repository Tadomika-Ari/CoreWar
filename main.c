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
    if (av[*i] == NULL || av[*i][0] != '-' || av[*i][1] != 'a')
        return;
    if (av[*i + 1] == NULL)
        return;
    tmp->position = my_getnbr(av[*i + 1]);
    *i = *i + 2;
}

static int parse_dump_flag(coreware_t *core, char **av, int *i)
{
    if (my_strcmp(av[*i], "-dump") != 0)
        return 0;
    if (av[*i + 1] == NULL)
        return my_puterror("error dump cycle missing\n", 84);
    core->dump_cycle = my_getnbr(av[*i + 1]);
    *i += 2;
    return 1;
}

static int add_champion(ll_t **list_champ, coreware_t *core, char **av, int *i)
{
    champ_t *tmp = init_champ(av, i);

    if (tmp == NULL)
        return my_puterror("error  init_champ\n", 84);
    push_to_back(list_champ, tmp);
    core->nb_champion++;
    return 0;
}

static int parse_args(coreware_t *core, ll_t **list_champ, char **av)
{
    int dump_status = 0;

    for (int i = 1; av[i] != NULL;) {
        dump_status = parse_dump_flag(core, av, &i);
        if (dump_status == 84)
            return 84;
        if (dump_status == 1)
            continue;
        if (add_champion(list_champ, core, av, &i) == 84)
            return 84;
    }
    return 0;
}

static int run_game(coreware_t *core, ll_t *list_champ, uint8_t *arena,
    char **av)
{
    if (write_in_arena(arena, core->nb_champion, av) == 84)
        return my_puterror("error write in arena\n", 84);
    loop(core, list_champ, arena);
    return 0;
}

void see_struct(ll_t *list_champ)
{
    champ_t *tmp = NULL;
    ll_t *next = NULL;

    while (list_champ != NULL) {
        next = list_champ->next;
        tmp = list_champ->data;
        list_champ = next;
    }
}

int init_struct(coreware_t *core)
{
    core->nb_champion = 0;
    core->nb_cyrcle_to_die = CYCLE_TO_DIE;
    core->dump_cycle = -1;
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

    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return help();
    init_struct(core);
    if (parse_args(core, &list_champ, av) == 84)
        return free_all(core, arena, list_champ);
    if (run_game(core, list_champ, arena, av) == 84)
        return free_all(core, arena, list_champ);
    return free_all(core, arena, list_champ);
}
