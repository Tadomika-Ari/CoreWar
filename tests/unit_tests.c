/*
** EPITECH PROJECT, 2026
** CoreWar
** File description:
** Unit tests for arena loading
*/

#include <criterion/criterion.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../include/robotfactorie.h"

static char *create_champ_file(const unsigned char *payload, size_t payload_size)
{
    char template_path[] = "/tmp/corewar_champ_XXXXXX";
    header_t header = {0};
    int fd = mkstemp(template_path);
    char *path = NULL;

    cr_assert(fd != -1, "mkstemp failed");
    cr_assert_eq(write(fd, &header, sizeof(header)), (ssize_t)sizeof(header));
    cr_assert_eq(write(fd, payload, payload_size), (ssize_t)payload_size);
    cr_assert_eq(close(fd), 0);
    path = strdup(template_path);
    cr_assert_not_null(path);
    return path;
}

static void destroy_champ_file(char *path)
{
    if (path == NULL)
        return;
    unlink(path);
    free(path);
}

Test(create_arena, returns_a_zeroed_arena)
{
    uint8_t *arena = create_arena();

    cr_assert_not_null(arena);
    for (size_t i = 0; i < MEM_SIZE; i++)
        cr_assert_eq(arena[i], 0);
    free(arena);
}

Test(create_arena, returns_distinct_allocations)
{
    uint8_t *first_arena = create_arena();
    uint8_t *second_arena = create_arena();

    cr_assert_not_null(first_arena);
    cr_assert_not_null(second_arena);
    cr_assert_neq(first_arena, second_arena);
    free(first_arena);
    free(second_arena);
}

Test(create_arena, first_cell_is_zero)
{
    uint8_t *arena = create_arena();

    cr_assert_not_null(arena);
    cr_assert_eq(arena[0], 0);
    free(arena);
}

Test(create_arena, middle_cell_is_zero)
{
    uint8_t *arena = create_arena();

    cr_assert_not_null(arena);
    cr_assert_eq(arena[MEM_SIZE / 2], 0);
    free(arena);
}

Test(create_arena, last_cell_is_zero)
{
    uint8_t *arena = create_arena();

    cr_assert_not_null(arena);
    cr_assert_eq(arena[MEM_SIZE - 1], 0);
    free(arena);
}

Test(my_getnbr, parses_positive_number)
{
    cr_assert_eq(my_getnbr("42"), 42);
}

Test(my_getnbr, parses_negative_number)
{
    cr_assert_eq(my_getnbr("-42"), -42);
}

Test(my_getnbr, parses_number_after_text)
{
    cr_assert_eq(my_getnbr("abc123"), 123);
}

Test(my_getnbr, parses_zero)
{
    cr_assert_eq(my_getnbr("0"), 0);
}

Test(my_getnbr, parses_number_with_leading_zeroes)
{
    cr_assert_eq(my_getnbr("0007"), 7);
}

Test(my_strcmp, returns_zero_for_equal_strings)
{
    cr_assert_eq(my_strcmp("corewar", "corewar"), 0);
}

Test(my_strcmp, returns_negative_when_first_is_smaller)
{
    cr_assert_lt(my_strcmp("abc", "abd"), 0);
}

Test(my_strcmp, returns_positive_when_first_is_greater)
{
    cr_assert_gt(my_strcmp("abd", "abc"), 0);
}

Test(my_strcmp, shorter_prefix_is_smaller)
{
    cr_assert_lt(my_strcmp("abc", "abcd"), 0);
}

Test(my_strcmp, empty_string_is_smaller_than_non_empty)
{
    cr_assert_lt(my_strcmp("", "a"), 0);
}

Test(write_in_arena, loads_one_champion_at_origin)
{
    const unsigned char payload[] = "HELLO";
    char *first = create_champ_file(payload, 5);
    char *av[] = {"./corewar", first, NULL};
    uint8_t *arena = create_arena();

    cr_assert_not_null(arena);
    cr_assert_eq(write_in_arena(arena, 1, av), 0);
    cr_assert_eq(arena[0], 'H');
    cr_assert_eq(arena[1], 'E');
    cr_assert_eq(arena[2], 'L');
    cr_assert_eq(arena[3], 'L');
    cr_assert_eq(arena[4], 'O');
    free(arena);
    destroy_champ_file(first);
}

Test(write_in_arena, loads_three_champions_with_equal_spacing)
{
    const unsigned char first_payload[] = "AAA";
    const unsigned char second_payload[] = "BBB";
    const unsigned char third_payload[] = "CCC";
    char *first = create_champ_file(first_payload, 3);
    char *second = create_champ_file(second_payload, 3);
    char *third = create_champ_file(third_payload, 3);
    char *av[] = {"./corewar", first, second, third, NULL};
    uint8_t *arena = create_arena();
    int step = MEM_SIZE / 3;

    cr_assert_not_null(arena);
    cr_assert_eq(write_in_arena(arena, 3, av), 0);
    cr_assert_eq(arena[0], 'A');
    cr_assert_eq(arena[step], 'B');
    cr_assert_eq(arena[step * 2], 'C');
    free(arena);
    destroy_champ_file(first);
    destroy_champ_file(second);
    destroy_champ_file(third);
}

Test(write_in_arena, rejects_negative_champion_count)
{
    char *av[] = {"./corewar", NULL};
    uint8_t *arena = create_arena();

    cr_assert_eq(write_in_arena(arena, -1, av), 84);
    free(arena);
}

Test(write_in_arena, rejects_missing_champion_path)
{
    char *av[] = {"./corewar", "-n", "1", NULL};
    uint8_t *arena = create_arena();

    cr_assert_eq(write_in_arena(arena, 1, av), 84);
    free(arena);
}

Test(write_in_arena, accepts_flags_before_single_champion)
{
    const unsigned char payload[] = "XYZ";
    char *first = create_champ_file(payload, 3);
    char *av[] = {"./corewar", "-dump", "10", "-a", "128", first, NULL};
    uint8_t *arena = create_arena();

    cr_assert_not_null(arena);
    cr_assert_eq(write_in_arena(arena, 1, av), 0);
    cr_assert_eq(arena[0], 'X');
    cr_assert_eq(arena[1], 'Y');
    cr_assert_eq(arena[2], 'Z');
    free(arena);
    destroy_champ_file(first);
}

Test(write_in_arena, writes_champions_at_expected_offsets)
{
    const unsigned char first_payload[] = "ABC";
    const unsigned char second_payload[] = "xyz";
    char *first = create_champ_file(first_payload, 3);
    char *second = create_champ_file(second_payload, 3);
    char *av[] = {"./corewar", first, second, NULL};
    uint8_t *arena = create_arena();

    cr_assert_not_null(arena);
    cr_assert_eq(write_in_arena(arena, 2, av), 0);
    cr_assert_eq(arena[0], 'A');
    cr_assert_eq(arena[1], 'B');
    cr_assert_eq(arena[2], 'C');
    cr_assert_eq(arena[MEM_SIZE / 2], 'x');
    cr_assert_eq(arena[(MEM_SIZE / 2) + 1], 'y');
    cr_assert_eq(arena[(MEM_SIZE / 2) + 2], 'z');
    free(arena);
    destroy_champ_file(first);
    destroy_champ_file(second);
}

Test(write_in_arena, skips_command_line_flags_before_champion_paths)
{
    const unsigned char first_payload[] = "123";
    const unsigned char second_payload[] = "456";
    char *first = create_champ_file(first_payload, 3);
    char *second = create_champ_file(second_payload, 3);
    char *av[] = {
        "./corewar",
        "-n",
        "42",
        first,
        "-a",
        "512",
        "-dump",
        "12",
        second,
        NULL
    };
    uint8_t *arena = create_arena();

    cr_assert_not_null(arena);
    cr_assert_eq(write_in_arena(arena, 2, av), 0);
    cr_assert_eq(arena[0], '1');
    cr_assert_eq(arena[1], '2');
    cr_assert_eq(arena[2], '3');
    cr_assert_eq(arena[MEM_SIZE / 2], '4');
    cr_assert_eq(arena[(MEM_SIZE / 2) + 1], '5');
    cr_assert_eq(arena[(MEM_SIZE / 2) + 2], '6');
    free(arena);
    destroy_champ_file(first);
    destroy_champ_file(second);
}

Test(write_in_arena, rejects_invalid_parameters)
{
    char *av[] = {"./corewar", NULL};
    uint8_t *arena = create_arena();

    cr_assert_eq(write_in_arena(NULL, 1, av), 84);
    cr_assert_eq(write_in_arena(arena, 0, av), 84);
    cr_assert_eq(write_in_arena(arena, 1, NULL), 84);
    free(arena);
}