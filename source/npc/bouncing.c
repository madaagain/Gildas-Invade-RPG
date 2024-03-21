/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** bouncing
*/

#include "npc.h"

static void bounce_entiti(entity_t *hit, entity_t *hitted)
{
    float angle =
atan2(hit->pos.y - hitted->pos.y, hit->pos.x - hitted->pos.x);

    hitted->move.x = -(2 * cos(angle));
    hitted->move.y = -(2 * sin(angle));
}

static void bounce_mob(entity_t *hit, entity_t *hitted)
{
    sfTime time = sfClock_getElapsedTime(hitted->bounce);
    if (hitted->bouncing == 1)
        bounce_entiti(hit, hitted);
    if (sfTime_asMilliseconds(time) >= 100) {
        hitted->move.x = 0.0;
        hitted->move.y = 0.0;
        hitted->bouncing = 0;
        sfClock_destroy(hitted->bounce);
    }
}

void bounce_event(entity_t *player, entity_t *mob)
{
    if (player->bouncing == 1)
        bounce_mob(mob, player);
}
