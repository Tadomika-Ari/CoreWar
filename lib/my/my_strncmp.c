/*
** EPITECH PROJECT, 2025
** my_strncmp
** File description:
** task07
*/

#include <stdio.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i;

    if (n == 0)
        return 0;
    for (i = 0; s1[i] != '\0' && s2[i] != '\0' && i < n; i++) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    if (i == n)
        return 0;
    return s1[i] - s2[i];
}
