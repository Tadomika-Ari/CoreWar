/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include <stdarg.h>
#include "struc_flag.h"
#include "../../../include/my.h"

int print_s(va_list ap, const char *format, int i)
{
    char *s = va_arg(ap, char *);

    my_putstr(s);
    return 0;
}
