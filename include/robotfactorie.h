/*
** EPITECH PROJECT, 2026
** RobotFactory
** File description:
** robotfactorie
*/

#include "my.h"
#include "op.h"

#ifndef ROBOTFACTORIE_H_
    #define ROBOTFACTORIE_H_

    #define NAME 1
    #define COM 2

typedef struct int_header {
    int index;
    int in_quotes;
}int_head_t;

typedef struct coreware_s {
    int nb_champion;
    int nb_cyrcle_to_die;
} coreware_t;

int help(void);
char ***open_file(const char *namefile);
header_t *get_header(char ***tab);


int print_into(char ***tab, char **av, header_t *header);
int get_prog_size(char ***tab);

#endif /* !ROBOTFACTORIE_H_ */
