/*
** EPITECH PROJECT, 2026
** help
** File description:
** flag_help
*/

#include "../include/robotfactorie.h"

int help(void)
{
    my_putstr("USAGE\n");
    my_putstr("./corewar [-dump nbr_cycle] [[-n prog_number] [");
    my_putstr("-a load_address] prog_name] ...\nDESCRIPTION\n");
    my_putstr("-n prog_number sets the next program’s number. By default,");
    my_putstr(" the first free number in the parameter order\n");
    my_putstr("-a load_address sets the next program’s loading address.");
    my_putstr("When no address is specified, optimize ");
    my_putstr("the addresses so that the processes ");
    my_putstr("are as far away from each other as possible. ");
    my_putstr("The addresses are MEM_SIZE modulo.\n");
    return 0;
}
