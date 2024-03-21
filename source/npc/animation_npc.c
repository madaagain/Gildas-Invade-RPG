/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-adam.zerrouk
** File description:
** animation_npc
*/

#include "player.h"
#include "npc.h"
#include "graphical.h"
#include "gamestate.h"


static void move_rect(entity_t *mob)
{
    mob->rect.left += 16;
    if (mob->rect.left >= 32)
        mob->rect.left = 0;
    sfSprite_setTextureRect(mob->sprite, mob->rect);
}

static void animate_mobs(npc_t *mob)
{
    while (mob) {
        if (!mob)
            break;
        move_rect(mob->mob);
        mob = mob->next;
    }
}

void animate_entities(entity_t *player, npc_t *mob, gamestate_t *gamestate)
{
    gamestate->time = sfClock_getElapsedTime(gamestate->anim);
    if (sfTime_asSeconds(gamestate->time) > 0.5) {
        animate_player(player);
        animate_mobs(mob);
        sfClock_restart(gamestate->anim);
    }
}
