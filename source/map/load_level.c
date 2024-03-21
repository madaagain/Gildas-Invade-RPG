/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** reload level
*/

#include "map.h"

layer_t *reload_level(layer_t *layer, int level, int floor)
{
    layer_t *new_layer = initialise_layer(level, floor);
    free_layer(layer);
    return (new_layer);
}
