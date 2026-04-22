/*
** EPITECH PROJECT, 2025
** my_put_nbr
** File description:
** task07
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
    }
    my_putchar('0' + (nb % 10));
    return 0;
}
