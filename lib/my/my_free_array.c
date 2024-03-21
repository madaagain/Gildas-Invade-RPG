/*
** EPITECH PROJECT, 2023
** free_array
** File description:
** my_free_array
*/

#include <stdlib.h>

void free_my_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}
