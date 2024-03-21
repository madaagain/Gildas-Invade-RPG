/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-adam.zerrouk
** File description:
** mobs_list
*/

#include "npc.h"

npc_t *add_node(npc_t *head, int x, int y, int type)
{
    npc_t *tmp = head;
    npc_t *new = malloc(sizeof(npc_t));
    new->next = NULL;
    new->mob = init_entity_npc(x, y, type);

    if (head == NULL) {
        head = new;
        return head;
    }

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new;
    return head;
}

static void kill_free_mob(npc_t *to_kill)
{
    sfSprite_destroy(to_kill->mob->sprite);
    sfTexture_destroy(to_kill->mob->texture);
    free(to_kill->mob);
    free(to_kill);
    to_kill = NULL;
}

npc_t *kill_mob(npc_t *head, npc_t *to_kill)
{
    npc_t *tmp = head;
    npc_t *to_next = head;
    if (head == NULL)
        return NULL;
    if (head == to_kill) {
        tmp = tmp->next;
        kill_free_mob(head);
        return tmp;
    }
    while (tmp->next != to_kill)
        tmp = tmp->next;
    if (!to_kill->next) {
        kill_free_mob(to_kill);
        tmp->next = NULL;
        return head;
    }
    to_next = to_kill->next;
    kill_free_mob(to_kill);
    tmp->next = to_next;
    return head;
}
