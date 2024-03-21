/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** get_utils
*/

#include "fight.h"

sfFloatRect *get_hitbox(entity_t *entity)
{
    sfFloatRect *rect = malloc(sizeof(sfFloatRect));
    rect->top = entity->pos.y;
    rect->left = entity->pos.x;
    rect->height = 16;
    rect->width = 16;
    return rect;
}

sfVector2f get_wpn_pos(entity_t *player)
{
    sfVector2f pos;

    if (player->dir == NORTH)
        pos = (sfVector2f) {player->pos.x, player->pos.y - 16};
    if (player->dir == EAST)
        pos = (sfVector2f) {player->pos.x + 16, player->pos.y};
    if (player->dir == SOUTH)
        pos = (sfVector2f) {player->pos.x, player->pos.y + 16};
    if (player->dir == WEST)
        pos = (sfVector2f) {player->pos.x - 16, player->pos.y};
    return pos;
}
