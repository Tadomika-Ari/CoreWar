/*
** EPITECH PROJECT, 2025
** struc_flag
** File description:
** struc pour cree des flag
*/

#ifndef STRUC_FLAG_H_
    #define STRUC_FLAG_H_

    #include <stdarg.h>

typedef struct struc_flag {
    char flag;
    int (*func)(va_list ap, const char *format, int i);
} struc_flag_t;

typedef struct struc_len_modif
{
    char flag;
    int (*func)(va_list ap);
} struc_len_modif_t;



#endif /* !STRUCFLAG_H_ */
