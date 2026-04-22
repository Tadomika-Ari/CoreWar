/*
** EPITECH PROJECT, 2025
** flag_u
** File description:
** flag_u
*/

#include <stdarg.h>
#include <stdio.h>
#include "struc_flag.h"
#include "../../../include/my.h"

static void my_put_nbr_unsigned(unsigned int nb)
{
    if (nb >= 10) {
        my_put_nbr_unsigned(nb / 10);
    }
    my_putchar('0' + (nb % 10));
}

int print_u(va_list ap, const char *format, int i)
{
    unsigned int variable = va_arg(ap, unsigned int);

    my_put_nbr_unsigned(variable);
    return variable;
}
