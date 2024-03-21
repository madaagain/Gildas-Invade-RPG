/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-adam.zerrouk
** File description:
** mouvement&attack_npc
*/

#include "map.h"
#include "my.h"
#include "player.h"
#include "fight.h"
#include "graphical.h"
#include "npc.h"


float distance_npc(sfVector2f abs, sfVector2f ord)
{
    float dx = abs.x - ord.x;
    float dy = abs.y - ord.y;

    return sqrt(dx * dx + dy * dy);
}

void if_invincible(entity_t *player)
{
    sfTime time;
    if (player->invicible == 1) {
        time = sfClock_getElapsedTime(player->invicibility);
        if (sfTime_asSeconds(time) > 2.0 && player->invicible == 1) {
            sfClock_destroy(player->invicibility);
            player->invicible = 0;
        }
    }
}

static void is_attacking(entity_t *player, entity_t *mob)
{
    sfFloatRect *box_player = get_hitbox(player);
    sfFloatRect *box_mob = get_hitbox(mob);
    if (sfFloatRect_intersects(box_player, box_mob, NULL) == sfTrue) {
        if (player->bouncing == 0 && player->invicible == 0) {
            player->bounce = sfClock_create();
            player->bouncing = 1;
        }
        if (player->invicible == 0) {
            player->invicibility = sfClock_create();
            hit(mob, player);
            player->invicible = 1;
        }
    }
    if_invincible(player);
}

void attack_player(entity_t *mob, entity_t *player)
{
    is_attacking(player, mob);
    float angle = atan2(player->pos.y - mob->pos.y, player->pos.x - mob->pos.x);

    mob->move.x = mob->speed * cos(angle);
    mob->move.y = mob->speed * sin(angle);
    bounce_event(player, mob);
}

void npc_move(entity_t *player, npc_t *head)
{
    float mob_distance = distance_npc(player->pos, head->mob->pos);

    if (mob_distance < ATTACK_RADIUS) {
        attack_player(head->mob, player);
    } else {
        float direction_elapsed =
        sfTime_asSeconds(sfClock_getElapsedTime(
        head->mob->mob_direction_clock));
        if (direction_elapsed >= head->mob->mob_direction_timer) {
            head->mob->direction = random_direction();
            sfClock_restart(head->mob->mob_direction_clock);
        }
        update_npc_position(head->mob, head->mob->direction);
    }
}
