/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-adam.zerrouk
** File description:
** npc
*/

#ifndef NPC_H_
    #define NPC_H_

    #include "player.h"

    typedef struct npc {
        struct npc *next;
        entity_t *mob;
    } npc_t;

    /* attack_npc.c */
    float distance_npc(sfVector2f abs, sfVector2f ord);
    void attack_player(entity_t *mob, entity_t *player);
    void npc_move(entity_t *player, npc_t *head);

    /*draw_npc.c*/
    void draw_mobs(npc_t *, sfRenderWindow *);
    void free_mobs(npc_t *);

    /* bouncing.c */
    void bounce_event(entity_t *player, entity_t *mob);

    /*initiate_npc.c*/
    npc_t *read_from_file(char const *filename);
    entity_t *init_entity_npc(int x, int y, int type);

    /* mob_list.c */
    npc_t *add_node(npc_t *head, int x, int y, int type);
    npc_t *kill_mob(npc_t *head, npc_t *to_kill);

    /* position_npc.c */
    float timer_rand_direct(float min , float max);
    int random_direction(void);
    sfVector2f random_position(float, float);
    void update_npc_position(entity_t *entity, int direction);

    npc_t *load_mobs_from_file(const char *filepath);

#endif /* !NPC_H_ */
