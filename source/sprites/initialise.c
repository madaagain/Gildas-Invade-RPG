/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** initialise tileset
*/

#include "map.h"

tilesheet_t *initialise_tileset(char *path)
{
    tilesheet_t *tileset = malloc(sizeof(tilesheet_t));
    tileset->rect = (sfIntRect){0, 0, 16, 16};
    tileset->texture = sfTexture_createFromFile(path, NULL);
    tileset->sprite = sfSprite_create();
    sfSprite_setTexture(tileset->sprite, tileset->texture, sfTrue);
    return (tileset);
}
