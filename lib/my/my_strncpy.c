/*
** EPITECH PROJECT, 2025
** strcpy
** File description:
** strcpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int index = 0;

    for (; src[index] != '\0' && index < n; index++) {
        dest[index] = src[index];
    }
    for (; src[index] != '\0'; index++) {
        dest[index] = '\0';
    }
    return dest;
}
