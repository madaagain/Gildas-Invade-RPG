/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-adam.zerrouk
** File description:
** init_npc
*/

#include "player.h"

float timer_rand_direct(float min , float max)
{
    float mob_range = max - min;
    return min + ((float)rand() / RAND_MAX) * mob_range;
}

int random_direction(void)
{
    int direction = rand() % 4;
    return direction;
}

sfVector2f random_position(float maxX, float maxY)
{
    int direction = rand() % 2;
    float x = (float)(rand() % (int)maxX);
    float y = (float)(rand() % (int)maxY);
    if (direction)
        x = -x;
    direction = rand() % 2;
    if (direction)
        y = -y;
    return (sfVector2f){x, y};
}

void update_npc_position(entity_t *entity, int direction)
{
    switch (direction) {
        case 0:
            entity->move.y = -entity->speed;
            entity->move.x = -entity->speed;
            break;
        case 1:
            entity->move.y = entity->speed;
            entity->move.x = entity->speed;
            break;
        case 2:
            entity->move.x = -entity->speed;
            entity->move.y = entity->speed;
            break;
        case 3:
            entity->move.y = -entity->speed;
            entity->move.x = entity->speed;
    }
}
