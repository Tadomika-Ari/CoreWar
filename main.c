/*
** EPITECH PROJECT, 2026
** main
** File description:
** robotfactori
*/

#include "include/robotfactorie.h"

void check_pos(champ_t *tmp, int *i, char **av)
{
    if (av[*i] != NULL && av[*i][0] == '-' && av[*i][1] == 'a') {
        if (av[*i + 1] != NULL) {
            tmp->position = my_getnbr(av[*i + 1]);
            *i = *i + 2;
        }
    }
}

champ_t *init_champ(char **av, int *i)
{
    champ_t *tmp = malloc(sizeof(champ_t));

    if (av[*i] == NULL || av[*i][0] != '-' || av[*i][1] != 'n') {
        printf("No nb");
        free(tmp);
        return NULL;
    }
    tmp->name_champ = my_getnbr(av[*i + 1]);
    *i = *i + 2;
    check_pos(tmp, i, av);
    if (av[*i] == NULL || av[*i][0] == '-') {
        printf("no file");
        free(tmp);
        return NULL;
    }
    tmp->file_champ = av[*i];
    *i = *i + 1;
    return tmp;
}

void see_struct(ll_t *list_champ)
{
    champ_t *tmp = NULL;
    ll_t *next = NULL;

    while (list_champ != NULL) {
        next = list_champ->next;
        tmp = list_champ->data;
        printf("NAME : %s\n", tmp->file_champ);
        printf("ID : %d\n", tmp->name_champ);
        free(tmp);
        free(list_champ);
        list_champ = next;
    }
}

int main(int ac, char **av)
{
    coreware_t *core = malloc(sizeof(coreware_t));
    ll_t *list_champ = NULL;
    champ_t *tmp = NULL;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return help();
    for (int i = 1; av[i] != NULL;) {
        tmp = init_champ(av, &i);
        if (tmp == NULL) {
            return 84;
        }
        push_to_front(&list_champ, tmp);
    }
    see_struct(list_champ);
    free(core);
    return OK;
}
