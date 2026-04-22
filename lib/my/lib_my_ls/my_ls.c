/*
** EPITECH PROJECT, 2025
** my_ls
** File description:
** my_ls
*/

#include "../../../include/my_ls.h"

static void free_all(my_ls_t *info)
{
    free(info->name_file);
    free(info);
}

int look_flag(char flags, my_ls_t *info)
{
    if (flags == 'a'){
        info->a = 1;
        return 0;
    }
    if (flags == 'l'){
        info->l = 1;
        return 0;
    }
    if (flags == 'd'){
        info->d = 1;
        return 0;
    } else if (flags != '\0') {
        my_printf("ls: invalid option -- '%c'\n", flags);
        return 84;
    }
    return 0;
}

void parting_flags_in_same_str(my_ls_t *info, char *strflags)
{
    int i = 1;

    if (strflags[0] != '-')
        return;
    while (strflags[i] != '\0'){
        if (look_flag(strflags[i], info) == 0)
            i++;
        else {
            free_all(info);
            return;
        }
    }
    return;
}

void parting_in_array(my_ls_t *info, char **av)
{
    for (int i = 0; av[i] != NULL; i++){
        if (av[i][0] == '-')
            parting_flags_in_same_str(info, av[i]);
    }
}

static int get_name_file(my_ls_t *info, char **av)
{
    int len = array_len(av);

    if (av[len - 1][0] != '-'){
        info->name_file = malloc(sizeof(char) * my_strlen(av[len - 1]) + 1);
        if (info->name_file == NULL)
            return 84;
        my_strcpy(info->name_file, av[len - 1]);
    } else {
        info->name_file = malloc(sizeof(char) * my_strlen(".") + 1);
        my_strcpy(info->name_file, ".");
    }
    return 0;
}

int my_ls(char **av, const char *files)
{
    my_ls_t *info = malloc(sizeof(my_ls_t));

    info->a = 0;
    info->d = 0;
    info->l = 0;
    get_name_file(info, av);
    if (av != NULL)
        parting_in_array(info, av);
    if (info == NULL)
        return 84;
    print_ls_files(info, info->name_file);
    free_all(info);
    return 0;
}
