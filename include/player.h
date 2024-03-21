/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    #define TXT_PLYR "./ressources/sprites/hero.png"
    #define TXT_NPC "./ressources/sprites/mob.png"
    #define ATTACK_RADIUS 45
    #define HAND 0
    #define SWORD 1
    #define BOW 2
    #define NORTH 1
    #define EAST 2
    #define SOUTH 3
    #define WEST 4
    #define RECT_HAND 0, 0, 16, 16
    #define RECT_SWORD 32, 0, 16, 16
    #define RECT_BOW 64, 32, 16, 16

    #include "map.h"
    #include "my.h"
    #include <stdlib.h>
    #include <stdlib.h>
    #include <time.h>
    #include <math.h>

    typedef struct entity_s {
        sfVector2f acceleration;
        sfVector2f move;
        sfVector2f pos;
        sfIntRect rect;
        int hp;
        int max_hp;
        int dmg;
        int xp;
        int alive;
        int dir;
        int type;
        float speed;
        float mob_direction_timer;
        int invicible;
        int silver_key;
        int gold_key;
        int direction;
        int bouncing;
        sfClock *bounce;
        sfClock *invicibility;
        sfClock *mob_direction_clock;
        sfClock *clock;
        sfTexture *texture;
        sfSprite *sprite;
        struct entity_s *weapon;
    } entity_t;

    /* draw_player.c */
    void draw_player(entity_t *, sfRenderWindow *);
    void rotate_sprite(entity_t *player, sfEvent *event);
    void animate_player(entity_t *player);

    /* init_player.c */
    entity_t *init_entity(void);

    float get_left_limit_traps(sfFloatRect player_rect, layer_t *layers,
entity_t *player);
    float get_right_limit_traps(sfFloatRect player_rect, layer_t *layers,
entity_t *player);
    float get_top_limit_traps(sfFloatRect player_rect, layer_t *layers,
entity_t *player);
    float get_bottom_limit_traps(sfFloatRect player_rect, layer_t *layers,
entity_t *player);
    void collision_traps(entity_t *player, layer_t *layers);
    void hit_player(entity_t *player, int dmg);

#endif /* !PLAYER_H_ */
