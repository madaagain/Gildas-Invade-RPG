/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** what type of door
*/

#include "event.h"

int is_locked_door(int type)
{
    if (type == 1 || type == 5 || type == 9 || type == 13) {
        return (1);
    }
    return (0);
}

int is_unlocked_door(int type)
{
    if (type == 3 || type == 7 || type == 11 || type == 15) {
        return (1);
    }
    return (0);
}

int is_open_door(int type)
{
    if (type == 4 || type == 8 || type == 12 || type == 16) {
        return (1);
    }
    return (0);
}
