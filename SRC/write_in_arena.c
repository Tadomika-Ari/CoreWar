/*
** EPITECH PROJECT, 2026
** write in arena
** File description:
** write_in_arena
*/

#include "../include/robotfactorie.h"

static char *get_next_champ_path(char **av, int *index)
{
    char *champ_path = NULL;

    while (av[*index] != NULL) {
        if (my_strcmp(av[*index], "-n") == 0 ||
            my_strcmp(av[*index], "-a") == 0 ||
            my_strcmp(av[*index], "-dump") == 0) {
            *index += 2;
            continue;
        }
        if (av[*index][0] == '-') {
            *index += 1;
            continue;
        }
        champ_path = av[*index];
        *index += 1;
        return champ_path;
    }
    return NULL;
}

static int read_all(int fd, uint8_t *buffer, size_t size)
{
    size_t total = 0;
    ssize_t bytes_read = 0;

    while (total < size) {
        bytes_read = read(fd, buffer + total, size - total);
        if (bytes_read < 0)
            return 84;
        if (bytes_read == 0)
            break;
        total += (size_t)bytes_read;
    }
    return total == size ? 0 : 84;
}

void init_write_struct(write_champ_t *tmp)
{
    tmp->champ_path = get_next_champ_path(tmp->av, &tmp->av_index);
    tmp->fd = 0;
    tmp->file_size = 0;
    tmp->code_size = 0;
    tmp->buffer = NULL;
    tmp->arena_index = 0;
}

int is_open_read(write_champ_t *tmp)
{
    tmp->fd = open(tmp->champ_path, O_RDONLY);
    if (tmp->fd == -1)
        return 84;
    tmp->file_size = lseek(tmp->fd, 0, SEEK_END);
    if (tmp->file_size == -1 || tmp->file_size <= (off_t)sizeof(header_t)) {
        close(tmp->fd);
        return 84;
    }
    tmp->buffer = malloc((size_t)tmp->file_size);
    if (tmp->buffer == NULL) {
        close(tmp->fd);
        return 84;
    }
    if (lseek(tmp->fd, 0, SEEK_SET) == -1 ||
        read_all(tmp->fd, tmp->buffer, (size_t)tmp->file_size) == 84) {
        free(tmp->buffer);
        close(tmp->fd);
        return 84;
    }
    return 0;
}

int loops_write(write_champ_t *tmp, uint8_t *arena)
{
    for (int champ_index = 0; champ_index < tmp->nb_champ; champ_index++) {
        init_write_struct(tmp);
        if (tmp->champ_path == NULL)
            return 84;
        if (is_open_read(tmp) == 84)
            return 84;
        tmp->code_size = (size_t)tmp->file_size - sizeof(header_t);
        for (size_t byte_index = 0; byte_index < tmp->code_size; byte_index++) {
            tmp->arena_index =
                ((size_t)champ_index * (size_t)tmp->start_step + byte_index) %
                MEM_SIZE;
            arena[tmp->arena_index] = tmp->buffer[sizeof(header_t)
                + byte_index];
        }
        free(tmp->buffer);
        close(tmp->fd);
    }
    return 0;
}

int write_in_arena(uint8_t *arena, int nb_champ, char **av)
{
    write_champ_t tmp;

    tmp.av_index = 1;
    tmp.start_step = 0;
    tmp.av = av;
    tmp.nb_champ = nb_champ;
    if (arena == NULL || av == NULL || nb_champ <= 0)
        return 84;
    tmp.start_step = MEM_SIZE / nb_champ;
    if (tmp.start_step <= 0)
        tmp.start_step = 1;
    return loops_write(&tmp, arena);
}
