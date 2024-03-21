/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** collid_hitbox
*/

#include "fight.h"
#include "npc.h"


int hit(entity_t *a, entity_t *b)
{
    int killed = 0;

    b->hp -= a->dmg;
    if (b->hp <= 0) {
        b->alive = 0;
        killed = 1;
    }
    return killed;
}

static int is_hit(entity_t* a, entity_t *b)
{
    sfFloatRect *rect_a = get_hitbox(a);
    sfFloatRect *rect_b = get_hitbox(b);
    int killed = 0;

    if (sfFloatRect_intersects(rect_a, rect_b, NULL) == sfTrue) {
        killed = hit(a, b);
    }
    free(rect_a);
    free(rect_b);
    return killed;
}

void free_mob(entity_t *mob)
{
    sfClock_destroy(mob->mob_direction_clock);
    sfTexture_destroy(mob->texture);
    sfSprite_destroy(mob->sprite);
}

void attack(entity_t *player, npc_t *mobs)
{
    int gain_xp = 0;

    if (!player->weapon)
        player->weapon = init_weapon(player);
    anim_weapon(player);
    if (mobs == NULL)
        return;
    if (player->weapon) {
        while (mobs) {
            gain_xp += is_hit(player->weapon, mobs->mob);
            mobs = mobs->next;
        }
    }
    player->xp += gain_xp * 50;
}
