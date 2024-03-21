/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** fight
*/

#ifndef FIGHT_H_
    #define FIGHT_H_

    #define SWORD_TXT "./ressources/sprites/final-sword-swoosh.png"
    #include "player.h"
    #include "graphical.h"
    #include "map.h"
    #include "moves.h"
    #include "npc.h"

    typedef struct arrow_s arrow_t;
    struct arrow_s {
        sfVector2f position;
        sfVector2f velocity;
        sfSprite *sprite;
        arrow_t *next;
    };

    /* anim_weapon.c */
    void anim_sword(entity_t *player);
    int move_sword(entity_t *weapon);
    void anim_weapon(entity_t *player);

    /* bow.c */

    /* collid_hitbox.c */
    int hit(entity_t *a, entity_t *b);
    void attack(entity_t *player, npc_t *mobs);

    /*get_utils.c */
    sfVector2f get_wpn_pos(entity_t *player);
    sfFloatRect *get_hitbox(entity_t *entity);

    /* initialisation.c */
    entity_t *init_weapon(entity_t *player);

    /* sword.c */

#endif /* !FIGHT_H_ */
