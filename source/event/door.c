/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** door
*/

#include "map.h"
#include "gamestate.h"
#include "event.h"

static int is_a_door(int type)
{
    if (type <= 14 && type >= 1) {
        return (1);
    }
    return (0);
}

sfVector2i find_adjacent_door(layer_t *layers, sfVector2i pos)
{
    if (is_a_door(layers[3].tiles[pos.y][pos.x - 1].type)) {
        pos.x -= 1;
        return (pos);
    }
    if (is_a_door(layers[3].tiles[pos.y][pos.x + 1].type)) {
        pos.x += 1;
        return (pos);
    }
    if (is_a_door(layers[3].tiles[pos.y - 1][pos.x].type)) {
        pos.y -= 1;
        return (pos);
    }
    if (is_a_door(layers[3].tiles[pos.y + 1][pos.x].type)) {
        pos.y += 1;
        return (pos);
    }
    return (pos);
}

sfVector2i find_closest_door(layer_t *layers, sfVector2i pos)
{
    for (int i = 0; layers[3].tiles[pos.y - 1][i].type != -1; i++) {
        if (is_a_door(layers[3].tiles[pos.y - 1][i].type)) {
            pos.x = i;
            pos.y -= 1;
            return (pos);
        }
    }
    for (int i = 0; layers[3].tiles[pos.y + 1][i].type != -1; i++) {
        if (is_a_door(layers[3].tiles[pos.y + 1][i].type)) {
            pos.x = i;
            pos.y += 1;
            return (pos);
        }
    }
    return (pos);
}

void open_close_door(layer_t *layers, sfVector2i pos, gamestate_t *gamestate)
{
    sfVector2i closest_door = find_closest_door(layers, pos);

    if (is_unlocked_door(layers[3].tiles[closest_door.y]
    [closest_door.x].type)) {
        sfSound_play(gamestate->sounds[1]);
        layers[3].tiles[closest_door.y][closest_door.x].type += 1;
        layers[0].tiles[closest_door.y][closest_door.x].type = 0;
    } else if (is_open_door(layers[3].tiles[closest_door.y]
    [closest_door.x].type)) {
        sfSound_play(gamestate->sounds[2]);
        layers[3].tiles[closest_door.y][closest_door.x].type -= 1;
        layers[0].tiles[closest_door.y][closest_door.x].type = 108;
    }
}

void unlock_door(layer_t *layers, sfVector2i closest_door)
{
    if (is_locked_door(layers[3].tiles[closest_door.y]
    [closest_door.x].type)) {
        layers[3].tiles[closest_door.y][closest_door.x].type += 2;
        layers[0].tiles[closest_door.y][closest_door.x].type = 108;
    }
}
