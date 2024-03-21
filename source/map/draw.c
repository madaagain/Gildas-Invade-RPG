/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** map display
*/

#include "map.h"

sfIntRect get_tile_rect(int type)
{
    sfIntRect rect = {0, 0, 16, 16};

    type -= 1;
    rect.left = (type % 18) * 16;
    rect.top = (type / 18) * 16;
    return (rect);
}

static sfIntRect get_item_rect(int type)
{
    sfIntRect rect = {0, 0, 16, 16};

    type -= 1;
    rect.left = (type % 4) * 16;
    rect.top = (type / 4) * 16;
    return (rect);
}

void draw_layer(tile_t **layer, tilesheet_t *tileset,
sfRenderWindow *window)
{
    for (int i = 0; layer[i]; i++) {
        for (int j = 0; layer[i][j].type != -1; j++) {
            tileset->rect = get_tile_rect(layer[i][j].type);
            sfSprite_setPosition(tileset->sprite, (sfVector2f){j * 16, i * 16});
            sfSprite_setTextureRect(tileset->sprite, tileset->rect);
            if (layer[i][j].type != 0)
                sfRenderWindow_drawSprite(window, tileset->sprite, NULL);
        }
    }
}

static void draw_items(tile_t **layer, tilesheet_t *tileset,
sfRenderWindow *window)
{
    for (int i = 0; layer[i]; i++) {
        for (int j = 0; layer[i][j].type != -1; j++) {
            tileset->rect = get_item_rect(layer[i][j].type);
            sfSprite_setPosition(tileset->sprite, (sfVector2f){j * 16, i * 16});
            sfSprite_setTextureRect(tileset->sprite, tileset->rect);
            if (layer[i][j].type != 0)
                sfRenderWindow_drawSprite(window, tileset->sprite, NULL);
        }
    }
}

void draw_map(layer_t *layers, sfRenderWindow *window)
{
    draw_layer(layers[1].tiles, layers[1].sprite_sheet, window);
    draw_layer(layers[2].tiles, layers[2].sprite_sheet, window);
    draw_layer(layers[3].tiles, layers[3].sprite_sheet, window);
    draw_items(layers[4].tiles, layers[4].sprite_sheet, window);
}
