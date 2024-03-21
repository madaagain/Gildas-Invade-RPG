/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-adam.zerrouk
** File description:
** npc_management
*/

#include "player.h"
#include "npc.h"
#include "moves.h"
#include "gamestate.h"

static npc_t *check_for_depop(npc_t *npc, npc_t **mobs)
{
    if (npc->mob->hp <= 0) {
        npc_t *next = npc->next;
        *mobs = kill_mob(*mobs, npc);
        return next;
    }
    return npc->next;
}

static void update_mob_pos(entity_t *mob)
{
    mob->pos.x += mob->move.x;
    mob->pos.y += mob->move.y;
    sfSprite_setPosition(mob->sprite, mob->pos);
    sfClock_restart(mob->clock);
}

void npc_management(gamestate_t *gamestate,
npc_t **mobs, layer_t *layers, entity_t *player)
{
    npc_t *tmp = *mobs;
    float time = 0.0;
    while (tmp) {
        tmp = check_for_depop(tmp, mobs);
        if (*mobs == NULL)
            return;
    }
    tmp = *mobs;
    while (tmp != NULL) {
        time = sfTime_asSeconds(sfClock_getElapsedTime(tmp->mob->clock));
        npc_move(player, tmp);
        collision(tmp->mob, layers);
        if (time > 0.01) {
            update_mob_pos(tmp->mob);
        }
        tmp = tmp->next;
    }
    draw_mobs(*mobs, gamestate->window);
}
