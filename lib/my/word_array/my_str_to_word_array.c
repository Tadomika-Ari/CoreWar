/*
** EPITECH PROJECT, 2025
** my str to word array
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../my.h"

struct array {
    int in_word;
    int count;
    int w;
    int i;
};


static int is_not_sepa(char c, char *separator)
{
    if (!separator)
        return 1;
    for (int i = 0; separator[i] != '\0'; i++) {
        if (c == separator[i])
            return 0;
    }
    if (c == '\n' || c == '\r' || c == '\t')
        return 0;
    return 1;
}

static int count_word(char *str, char *separator)
{
    int word = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_not_sepa(str[i], separator) && !in_word) {
            word++;
            in_word = 1;
        }
        if (!is_not_sepa(str[i], separator))
            in_word = 0;
    }
    return word;
}

static void check_sepa(char **tab, char *str, struct array *r, char *separator)
{
    if (is_not_sepa(str[r->i], separator)) {
        if (!r->in_word) {
            r->in_word = 1;
            r->count = 0;
        }
        r->count++;
    } else {
        if (r->in_word) {
            tab[r->w] = my_strndup(&str[r->i - r->count], r->count);
            r->w++;
            r->in_word = 0;
        }
    }
}

static void cpy_str_tab(char **tab, char *str, int word, char *separator)
{
    struct array r;

    r.i = 0;
    r.w = 0;
    r.count = 0;
    r.in_word = 0;
    for (; str[r.i] != '\0'; r.i++) {
        check_sepa(tab, str, &r, separator);
    }
    if (r.in_word) {
        tab[r.w] = my_strndup(&str[r.i - r.count], r.count);
        r.w++;
    }
    tab[r.w] = NULL;
}

char **my_str_to_word_array(char *str, char *separator)
{
    int word = 0;
    char **tab = NULL;

    if (str == NULL)
        return NULL;
    word = count_word(str, separator);
    if (word == 0)
        return NULL;
    tab = malloc(sizeof(char *) * (word + 1));
    if (tab == NULL)
        return NULL;
    cpy_str_tab(tab, str, word, separator);
    return tab;
}
