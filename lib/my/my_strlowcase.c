/*
** EPITECH PROJECT, 2025
** my strlowcase
** File description:
** lib
*/

char *my_strlowcase(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] <= 'Z' && str[i] >= 'A') {
            str[i] += 32;
        }
    }
    return str;
}
