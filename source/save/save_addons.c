/*
** EPITECH PROJECT, 2023
** save addons
** File description:
** rpg
*/

#include "my.h"

int power(int x, int y)
{
    if (y == 0) {
        return 1;
    }
    return x * power(x, y - 1);
}

int is_number(char *str)
{
    if (str[0] != '-' && (str[0] < '0' || str[0] > '9')) {
        return -1;
    }
    for (int i = 1; str[i] != '\0'; ++i) {
        if (str[i] < '0' || str[i] > '9') {
            return -1;
        }
    }
    return 0;
}

int str_to_int(char *str)
{
    int len = my_strlen(str) - 2;
    int return_value = 0;

    str[len + 1] = '\0';
    if (is_number(str) == -1) {
        return -1;
    }
    for (int i = 0; str[i] != '\0'; ++i) {
        return_value += ((str[i] - '0') * power(10, len));
        len -= 1;
    }
    return return_value;
}
