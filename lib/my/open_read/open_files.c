/*
** EPITECH PROJECT, 2025
** open files
** File description:
** open_files
*/

#include "../../../include/my.h"

int open_file_readonly(char *name_file)
{
    if (open(name_file, O_RDONLY) == -1) {
        my_printf("The file cannot be opened\n");
        return -1;
    }
    return open(name_file, O_RDONLY);
}
