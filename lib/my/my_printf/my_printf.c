/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** group mathis
*/

#include <stdarg.h>
#include <stdio.h>
#include "struc_flag.h"
#include "../../../include/my.h"

const struc_flag_t flags[] =
{
    {'i', print_i}, {'d', print_i}, {'%', print_percent},
    {'s', print_s}, {'c', print_c}, {'f', print_f},
    {'F', print_f}, {'u', print_u}, {'x', print_x},
    {'e', print_e}, {'E', print_e_upp}, {'X', print_maj_x},
    {'o', print_o}
};

int find_flag(const char *format, char c, va_list ap, int i)
{
    int j;
    int error = 0;
    int test = 0;

    for (j = 0; j <= 14; j++) {
        if (flags[j].flag == c) {
            i++;
            error++;
            test = flags[j].func(ap, format, i);
        }
    }
    if (error != 1) {
        my_putchar('%');
        my_putchar(c);
    }
    return format[i];
}

int my_printf(const char *format, ...)
{
    va_list ap;
    int i;
    int count = 0;
    char *str;

    va_start(ap, format);
    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
            my_putchar(format[i]);
            count++;
        } else {
            i++;
            find_flag(format, format[i], ap, i);
        }
    }
    return count;
}
