/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** free_entity
*/

#include "entity.h"

void destroy_player(entity_t *player)
{
    sfTexture_destroy(player->texture);
    sfSprite_destroy(player->sprite);
    sfClock_destroy(player->clock);
}
