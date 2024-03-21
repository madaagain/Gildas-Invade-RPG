/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** map include
*/

#ifndef MAP_H
    #define MAP_H

    #include "graphical.h"
    #include <stdlib.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <unistd.h>

typedef struct tile_s {
    int type;
    int properties;
} tile_t;

typedef struct tilesheet_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
} tilesheet_t;

typedef struct layer_s {
    tile_t **tiles;
    tilesheet_t *sprite_sheet;
    sfVector2i size;
} layer_t;

/* draw.c */
void draw_map(layer_t *layers, sfRenderWindow *window);

/* free_map.c */
void free_layer(layer_t *layer);

/* get_level_path.c */
char *get_level_path(char *level, char *floor, int type);

/* get_size .c */
sfVector2i get_size_map(layer_t layer);

/* initialise.c */
layer_t *initialise_layer(int level, int floor);

/* reload level */
layer_t *reload_level(layer_t *layer, int level, int floor);

int my_getnbr_pimp(char **str);
char **get_array_from_source(char *source);
sfIntRect get_tile_rect(int type);

#endif /* !MAP_H */
