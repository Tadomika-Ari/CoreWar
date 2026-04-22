/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** flag e
*/

#include <stdarg.h>
#include <math.h>
#include <stdio.h>
#include "../my.h"

static void display_char(int exp)
{
    my_putchar('E');
    my_putchar(exp >= 0 ? '+' : '-');
    if (exp < 0)
        exp = -exp;
    if (exp < 10)
        my_putchar('0');
    my_put_nbr(exp);
}

static void display_frac(double n, int prec)
{
    int ent;
    double frac;

    ent = (int)n;
    frac = n - ent;
    my_put_nbr(ent);
    my_putchar('.');
    for (int j = 0; j < prec; j++) {
        frac *= 10.0;
        my_putchar((int)frac + '0');
        frac -= (int)frac;
    }
}

static void isneg(double n)
{
    if (n < 0) {
        my_putchar('-');
        n = -n;
    }
}

int print_e_upp(va_list ap, const char *format, int i)
{
    double n = va_arg(ap, double);
    int exp = 0;
    int prec = 6;

    (void)format;
    (void)i;
    isneg(n);
    if (n == 0) {
        my_putstr("0.000000E+00");
        return 0;
    }
    for (; n >= 10.0; n /= 10.0)
        exp++;
    while (n < 1.0) {
        n *= 10.0;
        exp--;
    }
    display_frac(n, prec);
    display_char(exp);
    return 0;
}
