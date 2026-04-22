/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include <stdarg.h>
#include "../../../include/my.h"

int print_c(va_list ap, const char *format, int i)
{
    char c = va_arg(ap, int);

    my_putchar(c);
    return 0;
}
