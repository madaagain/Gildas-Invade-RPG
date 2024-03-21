/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** map initialiser
*/

#include "map.h"
#include "my.h"
#include "sprites.h"

char **get_array_from_source(char *source)
{
    int fd = open(source, O_RDONLY);
    struct stat st;
    char *buffer;
    stat(source, &st);
    buffer = malloc(sizeof(char) * st.st_size + 1);
    read(fd, buffer, st.st_size);
    buffer[st.st_size] = '\0';
    char **double_array = my_str_to_word_array_sep(buffer, '\n');
    free(buffer);
    close(fd);
    return (double_array);
}

int my_getnbr_pimp(char **str)
{
    int nb = 0;
    int neg = 1;

    while ((**str == '-' || **str == '+')) {
        if (**str == '-')
            neg *= -1;
        ++(*str);
    }
    while ((**str >= '0' && **str <= '9')) {
        nb = nb * 10 + **str - '0';
        (*str)++;
    }
    while ((**str == ',' || **str == ' '))
        ++(*str);
    return (nb * neg);
}

static tile_t *getnbr_on_line(char **line, tile_t *map_line, int len)
{
    for (int i = 0; i < len; i++) {
        map_line[i].type = my_getnbr_pimp(line);
        if (map_line[i].type >= 306)
            map_line[i].type -= 306;
        if (map_line[i].type >= 216)
            map_line[i].type -= 216;
        if (map_line[i].type >= 90)
            map_line[i].type -= 90;
    }
    map_line[len].type = -1;
    return (map_line);
}

static tile_t **initialise_map(char *source)
{
    char **buffer = get_array_from_source(source);
    tile_t **map = malloc(sizeof(tile_t *) * (my_array_len(buffer) + 1));
    int len = 0;
    char *copy;
    for (int i = 0; buffer[0][i] != '\0'; i++) {
        if (buffer[0][i] == ',')
            len++;
    }
    map[my_array_len(buffer)] = NULL;
    for (int i = 0; buffer[i]; i++) {
        map[i] = malloc(sizeof(tile_t) * (len + 1));
        copy = buffer[i];
        copy = my_strncpy(copy, buffer[i], my_strlen(buffer[i]));
        map[i] = getnbr_on_line(&copy, map[i], len);
        free(buffer[i]);
    }
    free(buffer);
    return (map);
}

layer_t *initialise_layer(int level, int floor)
{
    char lv[2] = "0";
    char fl[2] = "0";
    lv[0] += level;
    fl[0] += floor;
    layer_t *layer = malloc(sizeof(layer_t) * 5);
    layer[0].tiles = initialise_map(get_level_path(lv, fl, 0));
    layer[0].sprite_sheet = initialise_tileset("ressources/sprites/walls.png");
    layer[0].size = get_size_map(layer[0]);
    layer[1].tiles = initialise_map(get_level_path(lv, fl, 1));
    layer[1].sprite_sheet = initialise_tileset("ressources/sprites/floor.png");
    layer[2].tiles = initialise_map(get_level_path(lv, fl, 3));
    layer[2].sprite_sheet = initialise_tileset("ressources/sprites/deco.png");
    layer[3].tiles = initialise_map(get_level_path(lv, fl, 2));
    layer[3].sprite_sheet =
    initialise_tileset("ressources/sprites/interactible.png");
    layer[4].tiles = initialise_map(get_level_path(lv, fl, 4));
    layer[4].sprite_sheet =
    initialise_tileset("ressources/sprites/rpg-items.png");
    return (layer);
}
