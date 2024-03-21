/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** collision
*/

#include "map.h"
#include "player.h"
#include "graphical.h"
#include "moves.h"
#include <math.h>

float get_horizontal_limit(sfFloatRect player_rect, layer_t *layers,
entity_t *player)
{
    if (player->move.x > 0)
        return get_right_limit(player_rect, layers, player);
    if (player->move.x < 0)
        return get_left_limit(player_rect, layers, player);
    return 0.0;
}

float get_vertical_limit(sfFloatRect player_rect, layer_t *layers,
entity_t *player)
{
    if (player->move.y > 0)
        return get_bottom_limit(player_rect, layers, player);
    if (player->move.y < 0)
        return get_top_limit(player_rect, layers, player);
    return 0.0;
}

static void collision_part_two(entity_t *player, layer_t *layers,
sfFloatRect player_rect)
{
    float y_limit = get_vertical_limit(player_rect, layers, player);
    if (y_limit != 0.0) {
        if (player->move.y > 0 && player->pos.y +
        player->move.y + 16.0 > y_limit) {
            player->pos.y = y_limit - 16;
            player->move.y = 0;
        }
        if (player->move.y < 0 && player->pos.y + player->move.y < y_limit) {
            player->pos.y = y_limit;
            player->move.y = 0;
        }
    }
}

void collision(entity_t *player, layer_t *layers)
{
    sfFloatRect player_rect =
    {player->pos.x, player->pos.y + 6.0, 14.0, 10.0};

    float x_limit = get_horizontal_limit(player_rect, layers, player);
    if (x_limit != 0.0) {
        if (player->move.x > 0 && player->pos.x +
        player->move.x + 14.0 > x_limit) {
            player->pos.x = x_limit - 14;
            player->move.x = 0;
        }
        if (player->move.x < 0 && player->pos.x + player->move.x < x_limit) {
            player->pos.x = x_limit;
            player->move.x = 0;
        }
    }
    collision_part_two(player, layers, player_rect);
    collision_traps(player, layers);
}
