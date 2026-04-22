/*
** EPITECH PROJECT, 2025
** myswap
** File description:
** my_swap
*/

#include "my.h"

void my_swap(void **ptr_one, void **ptr_two)
{
    void *tmp = *ptr_one;

    *ptr_one = *ptr_two;
    *ptr_two = tmp;
}
