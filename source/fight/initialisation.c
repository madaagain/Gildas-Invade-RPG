/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** initialisation
*/

#include "fight.h"

static entity_t *init_sword(entity_t *player)
{
    entity_t *weapon = malloc(sizeof(entity_t));
    weapon->type = player->type;
    weapon->pos = get_wpn_pos(player);
    weapon->dmg = player->dmg;
    weapon->clock = sfClock_create();
    weapon->alive = 1;
    weapon->texture = sfTexture_createFromFile(SWORD_TXT, NULL);
    weapon->rect = (sfIntRect) {0, ((player->dir - 1) * 64),  64, 64};
    weapon->sprite = sfSprite_create();
    sfSprite_setPosition(weapon->sprite, weapon->pos);
    sfSprite_setTexture(weapon->sprite, weapon->texture, sfTrue);
    sfSprite_setTextureRect(weapon->sprite, weapon->rect);
    sfSprite_setScale(weapon->sprite, (sfVector2f){0.25, 0.25});
    return weapon;
}

entity_t *init_weapon(entity_t *player)
{
    if (player->type == SWORD)
        return (init_sword(player));
    return NULL;
}
