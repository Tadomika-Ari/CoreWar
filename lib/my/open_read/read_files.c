/*
** EPITECH PROJECT, 2025
** read files
** File description:
** read_files
*/

#include "../../../include/my.h"

int read_file(int open_file, char *buffer, size_t size)
{
    int bytes_read = read(open_file, buffer, size);

    if (bytes_read == -1) {
        my_printf("The file cannot be read\n");
        return 84;
    }
    return bytes_read;
}
