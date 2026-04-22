/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include <stdarg.h>
#include <math.h>
#include <stdio.h>
#include "struc_flag.h"
#include "../../../include/my.h"

int print_f(va_list ap, const char *format, int i)
{
    int ent;
    int dec;
    double nbr = va_arg(ap, double);

    ent = nbr;
    dec = 1000000 * (nbr - ent);
    my_put_nbr(ent);
    my_putchar('.');
    my_put_nbr(dec);
    return nbr;
}
