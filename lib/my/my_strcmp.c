/*
** EPITECH PROJECT, 2025
** my_strcomp
** File description:
** task06
*/

static int diff(char c1, char c2)
{
    if (c1 > c2)
        return 1;
    if (c1 < c2)
        return -1;
    return 0;
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return diff(s1[i], s2[i]);
        i++;
    }
    return diff(s1[i], s2[i]);
}
