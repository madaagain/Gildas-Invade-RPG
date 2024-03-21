/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** collisions
*/

#include "map.h"
#include "player.h"
#include "graphical.h"
#include "moves.h"
#include <math.h>

static int does_it_collide(int type)
{
    if (type == 0 || (type >= 31 && type <= 31 + 16))
        return (0);
    return (1);
}

float get_left_limit(sfFloatRect player_rect, layer_t *layers,
entity_t *player)
{
    int x = (int)floor((player_rect.left) / 16.0);
    int y = (int)floor((player_rect.top) / 16.0);
    int y2 = (int)floor((player_rect.top + player_rect.height) / 16.0);

    x -= 1;
    if (player->pos.y == y * 16)
        y2 -= 1;
    if (does_it_collide(layers[0].tiles[y][x].type))
        return ((x + 1) * 16);
    if (does_it_collide(layers[0].tiles[y2][x].type))
        return ((x + 1) * 16);
    return (0.0);
}

float get_right_limit(sfFloatRect player_rect, layer_t *layers,
entity_t *player)
{
    int x = (int)floor((player_rect.left + player_rect.width) / 16.0);
    int y = (int)floor((player_rect.top) / 16.0);
    int y2 = (int)floor((player_rect.top + player_rect.height) / 16.0);

    if (player->pos.y == y * 16)
        y2 -= 1;
    if (does_it_collide(layers[0].tiles[y][x].type))
        return (x * 16);
    if (does_it_collide(layers[0].tiles[y2][x].type))
        return (x * 16);
    return (0.0);
}

float get_top_limit(sfFloatRect player_rect, layer_t *layers,
entity_t *player)
{
    int x = (int)floor((player_rect.left) / 16.0);
    int x2 = (int)floor((player_rect.left + player_rect.width) / 16.0);
    int y = (int)floor((player_rect.top) / 16.0);

    y -= 1;
    if (player->pos.x == x * 16 + 2)
        x2 -= 1;
    if (does_it_collide(layers[0].tiles[y][x].type))
        return ((y + 1) * 16);
    if (does_it_collide(layers[0].tiles[y][x2].type))
        return ((y + 1) * 16);
    return (0.0);
}

float get_bottom_limit(sfFloatRect player_rect, layer_t *layers,
entity_t *player)
{
    int x = (int)floor((player_rect.left) / 16.0);
    int x2 = (int)floor((player_rect.left + player_rect.width) / 16.0);
    int y = (int)floor((player_rect.top + player_rect.height) / 16.0);

    if (player->pos.x == x * 16 + 2)
        x2 -= 1;
    if (does_it_collide(layers[0].tiles[y][x].type))
        return (y * 16);
    if (does_it_collide(layers[0].tiles[y][x2].type))
        return (y * 16);
    return (0.0);
}
