/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** hit_system
*/

#include "fight.h"

void do_damage(entity_t *entity, int dmg)
{
    if (entity->invicible == 0)
        entity->hp -= dmg;
    if (entity->hp <= 0)
        entity->alive = 0;
}

void is_invincible(entity_t *player)
{
    sfTime time;
    if (player->invicible == 1) {
        time = sfClock_getElapsedTime(player->invicibility);
        if (sfTime_asSeconds(time) >= 2.0) {
            player->invicible = 0;
            sfClock_destroy(player->invicibility);
        }
    }
}

void hit_player(entity_t *player, int dmg)
{
    if (player->invicible == 0) {
        do_damage(player, dmg);
        player->invicibility = sfClock_create();
        player->invicible = 1;
    }
}
