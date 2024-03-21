/*
** EPITECH PROJECT, 2023
** lib
** File description:
** array len
*/

#include <stddef.h>

int my_array_len(char *const *array)
{
    int len = 0;
    while (array[len] != NULL) {
        len += 1;
    }
    return len;
}
