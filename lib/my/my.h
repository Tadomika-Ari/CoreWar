/*
** EPITECH PROJECT, 2025
** libmy
** File description:
** libmy
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdarg.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <dirent.h>
    #include <string.h>
    #include <stdio.h>
    #include <errno.h>
    #include <pwd.h>
    #include <sys/stat.h>
    #include <pwd.h>
    #include <stdio.h>
    #include <grp.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

int print_files(int ac, char **av);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int array_len(char **tab);
int my_str_isnum(char const *str);
char **my_str_to_word_array2(char *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
char **my_str_to_word_array(char *str, char *separator);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_printf(const char *format, ...);
//! my_printf
int print_f(va_list ap, const char *format, int i);
int print_c(va_list ap, const char *format, int i);
int print_percent(va_list ap, const char *format, int i);
int print_s(va_list ap, const char *format, int i);
int print_i(va_list ap, const char *format, int i);
int format_p(va_list ap, const char *format, int i);
int print_e(va_list ap, const char *format, int i);
int print_e_upp(va_list ap, const char *format, int i);
int print_x(va_list ap, const char *format, int i);
int print_maj_x(va_list ap, const char *format, int i);
int print_o(va_list ap, const char *format, int i);
int print_u(va_list ap, const char *format, int i);
int format_blanck_space(va_list ap, const char *format, int i);
int find_flag(const char *format, char c, va_list ap, int i);
//! my_ls
int my_ls(int ac, char **av, const char *files);
int no_flags(int ac, char **av, char c, const char *files);
int find_flag_ls(int ac, char **av, char c, const char *files);
int flags_l_ls(int ac, char **av, char c, const char *files);
int print_ls_files(int ac, char **av, const char *files);
int flags_ls_a(int ac, char **av, char c, const char *files);
int flags_ls_d(int ac, char **av, char c, const char *files);
//! open_read
int open_file_readonly(char *name_file);
int read_file(int open_file, char *buffer, size_t size);


//! my_function
int my_puterror(char *message, int flags);
void my_free(void *ptr);
void *my_puterror_ptr(char *message);

typedef struct linked_list_s
{
    void *data;
    struct linked_list_s *next;
}ll_t;

int len_list(ll_t **list);
char *my_strndup(char const *str, int n);
int my_show_word_array(char **tab);
void my_free_array(char **tab);
void push_to_front(ll_t **begin, void *data);
void push_to_back(ll_t **begin, void *data);
void my_free_list(ll_t **list);

    #define MAX_INT = 2147483647
    #define MIN_INT = -2147483648

    #define MAX_CHAR = 127
    #define MIN_CHAR = -128

    #define ERROR 84
    #define FAIL -1
    #define OK 0
    #define SUCCES 1
    #define TRUE 1
    #define FALSE 0

#endif
