/*
** EPITECH PROJECT, 2025
** flag_o
** File description:
** flag_o
*/

#include <stdarg.h>
#include <stdio.h>
#include "struc_flag.h"
#include "../../../include/my.h"

int print_o(va_list ap, const char *format, int i)
{
    int nb = va_arg(ap, int);
    char tmp[20];
    int x = 0;

    while (nb >= 8) {
        tmp[x] = ('0' + (nb % 8));
        nb = nb / 8;
        x++;
    }
    tmp[x] = ('0' + (nb % 8));
    my_putstr(my_revstr(tmp));
    return 0;
}
