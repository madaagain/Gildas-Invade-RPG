/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** free_map
*/

#include "map.h"

void free_layer(layer_t *layer)
{
    for (int i = 0; i < 3; i++) {
        free(layer[i].tiles);
        sfTexture_destroy(layer[i].sprite_sheet->texture);
        sfSprite_destroy(layer[i].sprite_sheet->sprite);
        free(layer[i].sprite_sheet);
    }
    free(layer);
}
