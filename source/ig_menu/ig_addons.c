/*
** EPITECH PROJECT, 2023
** ig addons
** File description:
** rpg
*/

#include <stdlib.h>
#include "my.h"

int my_nblen(long nb)
{
    int len = 0;

    if (nb == 0)
        return 1;
    if (nb < 0) {
        len += 1;
        nb = -nb;
    }
    for (; nb > 0; ++len) {
        nb = nb / 10;
    }
    return len;
}

char *my_revstr(char *str)
{
    int index = 0;
    int length = my_strlen(str);
    char temp;

    while (index < length / 2) {
        temp = str[index];
        str[index] = str[length - index - 1];
        str[length - index - 1] = temp;
        index++;
    }
    return str;
}

char *int_to_str(int nb)
{
    int i = 0;
    char *res = malloc(sizeof(char) * (my_nblen(nb) + 10));

    if (res == NULL)
        return NULL;
    if (nb == 0) {
        res[0] = '0';
        res[1] = '\0';
        return res;
    }
    while (nb > 0) {
        res[i] = nb % 10 + '0';
        nb = nb / 10;
        i += 1;
    }
    res[i] = '\0';
    res = my_revstr(res);
    return res;
}
