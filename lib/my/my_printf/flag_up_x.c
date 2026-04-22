/*
** EPITECH PROJECT, 2025
** flag_X
** File description:
** flag_X
*/

#include <stdarg.h>
#include <stdio.h>
#include "struc_flag.h"
#include "../../../include/my.h"

static void nbr_hexadecimal_up(int nb)
{
    if (nb >= 10)
        nbr_hexadecimal_up(nb / 16);
    if (nb % 16 > 9)
        my_putchar((nb % 16) + ('A' - 10));
    if ((nb % 16) <= 9) {
        if ((nb % 16) > 0)
            my_putchar(nb % 16 + '0');
    }
}

int print_maj_x(va_list ap, const char *format, int i)
{
    int nb = va_arg(ap, int);

    nbr_hexadecimal_up(nb);
    return 0;
}
