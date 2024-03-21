/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** anim_weapon
*/

#include "fight.h"

int move_sword(entity_t *weapon)
{
    sfTime time = sfClock_getElapsedTime(weapon->clock);
    if (sfTime_asSeconds(time) > 0.1) {
        weapon->rect.left += 64;
        if (weapon->rect.left >= 64 * 3) {
            weapon->alive = 0;
            return 0;
        }
        sfSprite_setTextureRect(weapon->sprite, weapon->rect);
        sfClock_restart(weapon->clock);
    }
    return 0;
}

static void change_stance(entity_t *player)
{
    if (player->weapon) {
        player->type = HAND;
        player->rect = (sfIntRect) {RECT_HAND};
    } else {
        player->type = SWORD;
        player->rect = (sfIntRect) {RECT_SWORD};
    }
    sfSprite_setTextureRect(player->sprite, player->rect);
}

void anim_sword(entity_t *player)
{
    if (player->weapon->alive == 1) {
        move_sword(player->weapon);
    } else {
        sfTexture_destroy(player->weapon->texture);
        sfSprite_destroy(player->weapon->sprite);
        sfClock_destroy(player->weapon->clock);
        free(player->weapon);
        player->weapon = NULL;
    }
    change_stance(player);
}

void anim_weapon(entity_t *player)
{
    if (player->weapon) {
        if (player->weapon->type == SWORD)
            anim_sword(player);
    }
}
