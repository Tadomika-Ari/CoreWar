/*
** EPITECH PROJECT, 2025
** my_getnbr
** File description:
** lib
*/
#include <stdio.h>
#include "my.h"

int my_getnbr(char const *str)
{
    int result = 0;
    int n = 1;
    int c = 0;

    while (str[c] != '\0' && (str[c] < '0' || str[c] > '9')) {
        if (str[c] == '-') {
            n = n * -1;
        }
        c++;
    }
    for (; str[c] != '\0' && (str[c] >= '0' && str[c] <= '9'); c++) {
        result = result * 10 + (str[c] - 48);
    }
    result = result * n;
    return result;
}
