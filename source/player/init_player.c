/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** player
*/

#include "player.h"

static sfIntRect get_plyr_rect(int type)
{
    switch (type) {
        case HAND:
            return ((sfIntRect) {RECT_HAND});
        case SWORD:
            return ((sfIntRect) {RECT_SWORD});
        case BOW:
            return ((sfIntRect) {RECT_BOW});
        default:
            return ((sfIntRect) {RECT_HAND});
    }
}

static int get_dmg(int type)
{
    if (type == HAND)
        return 2;
    if (type == SWORD)
        return 50;
    if (type == BOW)
        return 5;
    return 2;
}

void init_values(entity_t *entity)
{
    entity->speed = 2;
    entity->dir = NORTH;
    entity->type = SWORD;
    entity->hp = 100;
    entity->invicible = 0;
    entity->bouncing = 0;
    entity->dmg = get_dmg(entity->type);
    entity->alive = 1;
    entity->invicible = 0;
}

entity_t *init_entity(void)
{
    entity_t *entity = malloc(sizeof(entity_t));
    entity->pos = (sfVector2f){500, 500};
    entity->move = (sfVector2f){0, 0};
    entity->clock = sfClock_create();
    entity->weapon = NULL;
    entity->xp = 0;
    entity->max_hp = 100;
    init_values(entity);
    entity->silver_key = 0;
    entity->gold_key = 0;
    entity->mob_direction_clock = sfClock_create();
    entity->rect = get_plyr_rect(entity->type);
    entity->texture = sfTexture_createFromFile(TXT_PLYR, NULL);
    entity->sprite = sfSprite_create();
    sfSprite_setTexture(entity->sprite, entity->texture, sfTrue);
    sfSprite_setTextureRect(entity->sprite, entity->rect);
    sfSprite_setPosition(entity->sprite, entity->pos);
    return (entity);
}
