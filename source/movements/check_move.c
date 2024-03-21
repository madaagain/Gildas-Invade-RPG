/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** check_move
*/

#include "moves.h"

void get_release(PLAYER, sfEvent *event)
{
    if (event->key.code == LEFT || event->key.code == RIGHT)
        player->move.x = 0;
    if (event->key.code == UP || event->key.code == DOWN)
        player->move.y = 0;
}

void get_move(PLAYER)
{
    if (sfKeyboard_isKeyPressed(LEFT)) {
        player->move.x = -MAX_SPEED;
        player->dir = WEST;
    }
    if (sfKeyboard_isKeyPressed(RIGHT)) {
        player->move.x = MAX_SPEED;
        player->dir = EAST;
    }
    if (sfKeyboard_isKeyPressed(UP)) {
        player->move.y = -MAX_SPEED;
        player->dir = NORTH;
    }
    if (sfKeyboard_isKeyPressed(DOWN)) {
        player->move.y = MAX_SPEED;
        player->dir = SOUTH;
    }
}

void do_move(PLAYER)
{
    sfTime time;

    is_invincible(player);
    time = sfClock_getElapsedTime(player->clock);
    if (sfTime_asSeconds(time) >= 0.01) {
        player->pos.x += player->move.x;
        player->pos.y += player->move.y;
        sfSprite_setPosition(player->sprite, player->pos);
        sfClock_restart(player->clock);
    }
}
