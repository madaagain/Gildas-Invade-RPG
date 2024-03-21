/*
** EPITECH PROJECT, 2022
** strcat
** File description:
** only file
*/

#include "my.h"

char *my_strcat(char *dest, char *src)
{
    char *tmp = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
    int a = my_strlen(dest);

    for (int i = 0; dest[i] != '\0'; i++)
        tmp[i] = dest[i];
    for (int i = 0; src[i] != '\0'; i++)
        tmp[a + i] = src[i];
    tmp[a + my_strlen(src)] = '\0';
    free(dest);
    return tmp;
}
