/*
** EPITECH PROJECT, 2023
** include hud
** File description:
** rpg
*/

#ifndef INCLUDE_HUD_H_
    #define INCLUDE_HUD_H_
    #include "graphical.h"

typedef struct hud {
    sfRectangleShape* health_back;
    sfRectangleShape* health_bar;
    sfRectangleShape* xp_back;
    sfRectangleShape* xp_bar;
} hud_t;

hud_t *init_hud(void);
void update_health_bar(int health, int hp_max,
        hud_t *hud, sfView *view);
void display_hud(sfRenderWindow *window, hud_t *hud);
void update_xp_bar(int xp, hud_t *hud, sfView *view);
void update_stats(entity_t *player);

#endif /* INCLUDE_HUD_H_ */
