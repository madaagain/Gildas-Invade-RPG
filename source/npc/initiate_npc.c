/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-adam.zerrouk
** File description:
** initiate_npc
*/

#include "player.h"
#include "npc.h"

static void assign_stats(entity_t *entity)
{
    if (entity->type == 1 || entity->type == 2 ||
    entity->type == 3 || entity->type == 4) {
        entity->hp = 100;
        entity->dmg = 10;
        entity->speed = 0.5f;
    }
    if (entity->type == 5 || entity->type == 6 ||
    entity->type == 7 || entity->type == 8) {
        entity->hp = 200;
        entity->dmg = 20;
        entity->speed = 0.7f;
    }
    if (entity->type == 9 || entity->type == 10 ||
    entity->type == 11 || entity->type == 12) {
        entity->hp = 400;
        entity->dmg = 50;
        entity->speed = 0.3f;
    }
}

entity_t *init_entity_npc(int x, int y, int type)
{
    entity_t *entity = malloc(sizeof(entity_t));
    entity->pos = (sfVector2f){(float) x, (float) y};
    entity->type = type;
    entity->move = (sfVector2f){0, 0};
    entity->speed = 0.5f;
    entity->bouncing = 0;
    entity->rect = (sfIntRect){0, 0, 16, 16};
    entity->rect.top = (type - 1) * 16;
    entity->texture = sfTexture_createFromFile(TXT_NPC, NULL);
    entity->sprite = sfSprite_create();
    entity->clock = sfClock_create();
    assign_stats(entity);
    sfSprite_setTexture(entity->sprite, entity->texture, sfTrue);
    sfSprite_setTextureRect(entity->sprite, entity->rect);
    sfSprite_setPosition(entity->sprite, entity->pos);
    entity->direction = random_direction();
    entity->mob_direction_timer = 1.0f;
    entity->mob_direction_clock = sfClock_create();
    return entity;
}
