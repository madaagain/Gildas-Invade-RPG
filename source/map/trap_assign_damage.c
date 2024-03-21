/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** assign trap damage
*/

#include "map.h"
#include "player.h"
#include "graphical.h"
#include "moves.h"
#include <math.h>

static void collision_traps_part_two(entity_t *player, layer_t *layers)
{
    sfFloatRect player_rect = {player->pos.x, player->pos.y + 0, 14.0, 6.0};

    sfVector2i top_right_tile =
    {(int) floor((player_rect.left + player_rect.width) / 16),
    (int) floor((player_rect.top) / 16)};
    sfVector2i bottom_left_tile =
    {(int) floor((player_rect.left) / 16), (int) floor((player_rect.top +
    player_rect.height) / 16)};
    if (layers[3].tiles[top_right_tile.y][top_right_tile.x].type == 57 ||
    layers[3].tiles[top_right_tile.y][top_right_tile.x].type == 58)
        hit_player(player, 10);
    if (layers[3].tiles[bottom_left_tile.y][bottom_left_tile.x].type == 57 ||
    layers[3].tiles[bottom_left_tile.y][bottom_left_tile.x].type == 58)
        hit_player(player, 10);
}

void collision_traps(entity_t *player, layer_t *layers)
{
    sfFloatRect player_rect = {player->pos.x, player->pos.y + 9, 14.0, 6.0};

    sfVector2i top_left_tile =
    {(int) floor(player_rect.left / 16),
    (int) floor(player_rect.top / 16)};
    sfVector2i bottom_right_tile =
    {(int) floor((player_rect.left + player_rect.width) / 16),
    (int) floor((player_rect.top + player_rect.height) / 16)};
    if (layers[3].tiles[bottom_right_tile.y][bottom_right_tile.x].type == 57 ||
    layers[3].tiles[bottom_right_tile.y][bottom_right_tile.x].type == 58)
        hit_player(player, 10);
    if (layers[3].tiles[top_left_tile.y][top_left_tile.x].type == 57 ||
    layers[3].tiles[top_left_tile.y][top_left_tile.x].type == 58)
        hit_player(player, 10);
    collision_traps_part_two(player, layers);
}
