/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** draw_player
*/

#include "player.h"
#include "moves.h"

static sfIntRect animation(sfIntRect curr, sfIntRect origin)
{
    curr.left += 16;
    if (curr.left >= origin.left + 32)
        curr.left = origin.left;
    return curr;
}

void rotate_sprite(entity_t *player, sfEvent *event)
{
    sfVector2f scale = sfSprite_getScale(player->sprite);
    sfVector2f origin = sfSprite_getOrigin(player->sprite);
    if (event->key.code == LEFT && scale.x > 0) {
        scale.x = -scale.x;
        origin.x = 16;
        sfSprite_setOrigin(player->sprite, origin);
    }
    if (event->key.code == RIGHT && scale.x < 0) {
        scale.x = -scale.x;
        origin.x = 8;
        sfSprite_setOrigin(player->sprite, origin);
    }
    sfSprite_setScale(player->sprite, scale);
}

void animate_player(entity_t *player)
{
    sfIntRect rect;
    rect = player->rect;
    if (player->type == HAND)
        rect = animation(rect, (sfIntRect){RECT_HAND});
    if (player->type == SWORD)
        rect = animation(rect, (sfIntRect){RECT_SWORD});
    if (player->type == BOW)
        rect = animation(rect, (sfIntRect){RECT_BOW});
    player->rect = rect;
    sfSprite_setTextureRect(player->sprite, player->rect);
}

void draw_player(entity_t *player, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, player->sprite, NULL);
    if (player->weapon && player->weapon->alive == 1) {
        sfRenderWindow_drawSprite(window, player->weapon->sprite, NULL);
    }
}
