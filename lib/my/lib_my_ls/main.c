/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include "../../../include/my_ls.h"

int main(int ac, char **av)
{
    if (ac == 1) {;
        return my_ls(NULL, ".");
    }
    return my_ls(av, av[1]);
}
