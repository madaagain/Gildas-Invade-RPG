/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** chest event
*/

#include "gamestate.h"
#include "event.h"
#include "entity.h"

void get_chest_event(PLAYER, layer_t *layers, gamestate_t **gamestate)
{
    sfVector2i closest_tile = get_closest_tile(player);

    if (layers[3].tiles[closest_tile.y][closest_tile.x].type == 21)
        (*gamestate)->is_end = 1;
}
