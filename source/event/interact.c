/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** interact
*/

#include "player.h"
#include "gamestate.h"
#include "map.h"
#include "npc.h"
#include "event.h"
#include <math.h>

sfVector2i get_closest_tile(entity_t *player)
{
    sfVector2i pos = {0, 0};

    pos.x = (player->pos.x + 8) / 16;
    pos.y = (player->pos.y + 8) / 16;
    return (pos);
}

static layer_t *manage_floor_events(entity_t *player,
layer_t *layers, gamestate_t **gamestate, npc_t **npc)
{
    sfVector2i pos = get_closest_tile(player);
    int type = layers[3].tiles[pos.y][pos.x].type;
    int check = 0;
    check = return_check(type, gamestate);
    if (check) {
        layers =
        reload_level(layers, (*gamestate)->level, (*gamestate)->floor);
        (*gamestate)->mobs =
        reload_mobs(gamestate);
        return (layers);
    }
    return (layers);
}

static void manage_door_events(entity_t *player, layer_t *layers,
gamestate_t *gamestate)
{
    sfVector2i pos = get_closest_tile(player);
    int type = layers[3].tiles[pos.y][pos.x].type;
    sfVector2i closest_door = find_adjacent_door(layers, pos);
    if (type == 29) {
        sfSound_play(gamestate->sounds[0]);
        layers[3].tiles[pos.y][pos.x].type = 31;
        open_close_door(layers, pos, gamestate);
    }
    if (type == 31) {
        sfSound_play(gamestate->sounds[0]);
        layers[3].tiles[pos.y][pos.x].type = 29;
        open_close_door(layers, pos, gamestate);
    }
    if ((closest_door.x != pos.x || closest_door.y != pos.y)) {
        if (is_locked_door(layers[3].tiles[closest_door.y]
        [closest_door.x].type) && player->silver_key > 0) {
            unlock_door(layers, closest_door);
            player->silver_key -= 1;
        }
    }
}

static void manage_item_events(entity_t *player, layer_t *layers)
{
    sfVector2i pos = get_closest_tile(player);
    int type = layers[4].tiles[pos.y][pos.x].type;

    if (type == 15) {
        player->silver_key += 1;
        layers[4].tiles[pos.y][pos.x].type = 0;
    }
    if (type == 16) {
        player->gold_key += 1;
        layers[4].tiles[pos.y][pos.x].type = 0;
    }
    if (type == 19) {
        player->hp += 50;
        layers[4].tiles[pos.y][pos.x].type = 0;
    }
}

layer_t *interact(entity_t *player, layer_t *layers,
gamestate_t **gamestate, npc_t **npc)
{
    manage_door_events(player, layers, *gamestate);
    manage_item_events(player, layers);
    layers = manage_floor_events(player, layers, gamestate, npc);
    get_chest_event(player, layers, gamestate);
    return (layers);
}
