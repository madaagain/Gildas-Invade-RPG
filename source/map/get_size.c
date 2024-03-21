/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** get_size
*/

#include "map.h"

sfVector2i get_size_map(layer_t layer)
{
    int i = 0;
    int j = 0;
    int max_x = 0;
    sfVector2i pos;

    for (; layer.tiles[i] ; i++) {
        for (j = 0;layer.tiles[i][j].type != -1; j++) {
        }
        max_x = ((j > max_x) ? j : max_x);
    }
    pos.x = max_x;
    pos.y = i;
    return pos;
}
