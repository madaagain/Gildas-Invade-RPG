/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** moves
*/

#ifndef MOVES_H_
    #define MOVES_H_

    #define PX player->pos.x
    #define PY player->pos.y
    #define MAX_SPEED 1.0
    #define DASH_SPEED 10
    #define SPEED player->speed
    #define PLAYER entity_t *player
    #define LAYER layer_t *layer
    #define LEFT sfKeyQ
    #define RIGHT sfKeyD
    #define UP sfKeyZ
    #define DOWN sfKeyS
    #define PUSH_BACK 2

    #include <stdio.h>
    #include "graphical.h"
    #include "moves.h"
    #include "map.h"
    #include "player.h"

    /* check_move.c */
    void get_release(PLAYER, sfEvent *event);
    void get_move(PLAYER);
    void do_move(PLAYER);

    /* collision.c */
    int push_back(PLAYER, LAYER);
    void collision(PLAYER, LAYER);
    float get_left_limit(sfFloatRect player_rect, LAYER, PLAYER);
    float get_right_limit(sfFloatRect player_rect, LAYER, PLAYER);
    float get_top_limit(sfFloatRect player_rect, LAYER, PLAYER);
    float get_bottom_limit(sfFloatRect player_rect, LAYER, PLAYER);

#endif /* !MOVES_H_ */
