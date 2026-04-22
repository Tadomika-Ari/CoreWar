/*
** EPITECH PROJECT, 2025
** MyProject
** File description:
** MyFile
*/

#include <stdarg.h>
#include "struc_flag.h"
#include "../../../include/my.h"

int print_i(va_list ap, const char *format, int i)
{
    int variable = va_arg(ap, int);

    my_put_nbr(variable);
    return variable;
}
