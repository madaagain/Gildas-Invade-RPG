/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-adam.zerrouk
** File description:
** draw_npc
*/

#include "npc.h"

void draw_mobs(npc_t *npc, sfRenderWindow *window)
{
    npc_t *tmp = npc;

    if (npc == NULL)
        return;
    while (tmp) {
        sfRenderWindow_drawSprite(window, tmp->mob->sprite, sfFalse);
        tmp = tmp->next;
    }
}

void free_mobs(npc_t *head)
{
    npc_t *tmp = head;

    while (tmp != NULL) {
        head = tmp;
        tmp = tmp->next;
        sfTexture_destroy(head->mob->texture);
        sfSprite_destroy(head->mob->sprite);
        sfClock_destroy(head->mob->clock);
        free(head->mob);
        free(head);
    }
}
