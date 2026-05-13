/*
** EPITECH PROJECT, 2026
** RobotFactory
** File description:
** robotfactorie
*/

#include "my.h"
#include "op.h"
#include <stdint.h>

#ifndef ROBOTFACTORIE_H_
    #define ROBOTFACTORIE_H_

    #define NAME 1
    #define COM 2

typedef struct champ {
    char *file_champ;
    int size;
    int name_champ;
    int position;
    int is_active;
} champ_t;

typedef struct int_header {
    int index;
    int in_quotes;
}int_head_t;

typedef struct coreware_s {
    int nb_champion;
    int nb_cyrcle_to_die;
} coreware_t;

typedef struct write {
    int fd;
    off_t file_size;
    size_t code_size;
    uint8_t *buffer;
    int av_index;
    int start_step;
    int nb_champ;
    char **av;
    char *champ_path;
    size_t arena_index;
}write_champ_t;

int help(void);
char ***open_file(const char *namefile);
header_t *get_header(char ***tab);


int print_into(char ***tab, char **av, header_t *header);
int get_prog_size(char ***tab);
uint8_t *create_arena(void);
int write_in_arena(uint8_t *arena, int nb_champ, char **av);
champ_t *init_champ(char **av, int *i);
void check_pos(champ_t *tmp, int *i, char **av);
int loop(coreware_t *core, ll_t *list_champ);
int set_champ_dead(ll_t *list_champ, coreware_t *core, int champ_target);
void see_struct(ll_t *list_champ);

#endif /* !ROBOTFACTORIE_H_ */
