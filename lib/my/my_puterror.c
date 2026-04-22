/*
** EPITECH PROJECT, 2026
** my_puterror
** File description:
** my_puterror
*/

#include "my.h"

int my_puterror(char *message, int flags)
{
    write(2, message, my_strlen(message));
    return flags;
}

void *my_puterror_ptr(char *message)
{
    write(2, message, my_strlen(message));
    return NULL;
}
