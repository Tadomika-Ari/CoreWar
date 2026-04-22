/*
** EPITECH PROJECT, 2025
** flag_x
** File description:
** flag_x
*/

#include <stdarg.h>
#include <stdio.h>
#include "struc_flag.h"
#include "../../../include/my.h"

static void nbr_hexadecimal(int nb)
{
    if (nb >= 10)
        nbr_hexadecimal(nb / 16);
    if (nb % 16 > 9)
        my_putchar((nb % 16) + ('a' - 10));
    if ((nb % 16) <= 9) {
        if ((nb % 16) > 0)
            my_putchar(nb % 16 + '0');
    }
}

int print_x(va_list ap, const char *format, int i)
{
    int nb = va_arg(ap, int);

    nbr_hexadecimal(nb);
    return 0;
}
