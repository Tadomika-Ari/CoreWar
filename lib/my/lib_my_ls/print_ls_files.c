/*
** EPITECH PROJECT, 2025
** ls
** File description:
** print_ls_files
*/

#include "../../../include/my_ls.h"
#include <time.h>

static void print_permision(char *name)
{
    struct stat sb;
    mode_t mode;

    if (stat(name, &sb) == 0){
        mode = sb.st_mode;
        my_printf("%c%c%c%c%c%c%c%c%c",
            (mode & S_IRUSR) ? 'r' : '-',
            (mode & S_IWUSR) ? 'w' : '-',
            (mode & S_IXUSR) ? 'x' : '-',
            (mode & S_IRGRP) ? 'r' : '-',
            (mode & S_IWGRP) ? 'w' : '-',
            (mode & S_IXGRP) ? 'x' : '-',
            (mode & S_IROTH) ? 'r' : '-',
            (mode & S_IWOTH) ? 'w' : '-',
            (mode & S_IXOTH) ? 'x' : '-');
    }
}

static void print_user_groups_and_octet(char *name)
{
    struct stat sb;
    struct group *group;
    struct passwd *pw;

    if (stat(name, &sb) == 0){
        group = getgrgid(sb.st_uid);
        pw = getpwuid(sb.st_uid);
        my_printf("%d %s %s %d", sb.st_nlink, pw->pw_name
            , group->gr_name, sb.st_size);
    }
}

static void print_time(char *name)
{
    struct stat sb;
    char *time_str;

    if (stat(name, &sb) == 0){
        time_str = ctime(&sb.st_mtime);
        my_putchar(time_str[11]);
        my_putchar(time_str[12]);
        my_putchar(':');
        my_putchar(time_str[14]);
        my_putchar(time_str[15]);
    }
}

static void print_date_and_time(char *name)
{
    struct stat sb;
    char *time_str;

    if (stat(name, &sb) == 0){
        time_str = ctime(&sb.st_mtime);
        my_putchar(time_str[4]);
        my_putchar(time_str[5]);
        my_putchar(time_str[6]);
        my_putchar(' ');
        if (time_str[8] == ' ')
            my_putchar(' ');
        else
            my_putchar(time_str[8]);
        my_putchar(time_str[9]);
        my_putchar(' ');
        print_time(name);
    }
}

static void print_ls(my_ls_t *info, char *name)
{
    if (info->l == 1) {
        print_permision(name);
        print_user_groups_and_octet(name);
    }
    my_printf(" %s ", name);
    if (info->l == 1) {
        print_date_and_time(name);
        my_putchar('\n');
    }
}

static int case_error(char *name)
{
    if (my_strcmp(name, ".") == 0 ||
        my_strcmp(name, "..") == 0 ||
        my_strcmp(name, ".git") == 0 ||
        my_strcmp(name, ".gitignore") == 0) {
        return 84;
    }
    return 0;
}

static DIR *opendir_ls(const char *name)
{
    DIR *fd = opendir(name);

    if (fd == NULL) {
        my_printf("ls: cannot access '%s': No such file or directory \n"
            , name);
        return NULL;
    }
    return fd;
}

static void flags_d(my_ls_t *info)
{
    print_ls(info, ".");
    if (info->l != 1)
        my_putchar('\n');
}

int print_ls_files(my_ls_t *info, const char *files)
{
    DIR *fd = opendir_ls(files);
    struct dirent *read;
    struct stat sb;

    if (fd == NULL)
        return 84;
    read = readdir(fd);
    for (; read != NULL; read = readdir(fd)) {
        if (info->d == 1){
            flags_d(info);
            return 0;
        }
        if (case_error(read->d_name) == 84 && info->a != 1)
            continue;
        print_ls(info, read->d_name);
    }
    if (info->l != 1)
        my_putchar('\n');
    closedir(fd);
    return 0;
}
