/*
** EPITECH PROJECT, 2023
** MyRPG check
** File description:
** return check
*/

#include "gamestate.h"

int return_check(int type, gamestate_t **gamestate)
{
    int check = 0;
    if (type == 20 || type == 33) {
        (*gamestate)->floor += 1;
        check = 1;
    }
    if (type == 19 || type == 32) {
        (*gamestate)->floor -= 1;
        check = 1;
    }
    return (check);
}
