/*
** EPITECH PROJECT, 2022
** my getnbr
** File description:
** get nbr
*/

#include "../../include/my.h"

int my_getnbr(char **str)
{
    long number = 0;
    int sign = 1;

    if (**str == '-') {
        sign = -1;
        (*str)++;
    }
    while (**str >= '0' && **str <= '9') {
        number *= 10;
        number += **str - '0';
        (*str)++;
    }
    (*str)++;
    return number * sign;
}
