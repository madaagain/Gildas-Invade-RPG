/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** hud
*/

#include "gamestate.h"
#include "hud.h"

hud_t *init_hud(void)
{
    hud_t *hud = malloc(sizeof(hud_t));

    hud->health_back = sfRectangleShape_create();
    sfRectangleShape_setSize(hud->health_back, (sfVector2f){30, 5});
    sfRectangleShape_setFillColor(hud->health_back, sfBlack);
    hud->health_bar = sfRectangleShape_create();
    sfRectangleShape_setSize(hud->health_bar, (sfVector2f){29, 4});
    sfRectangleShape_setFillColor(hud->health_bar, sfRed);
    hud->xp_back = sfRectangleShape_create();
    sfRectangleShape_setSize(hud->xp_back, (sfVector2f){30, 5});
    sfRectangleShape_setFillColor(hud->xp_back, sfBlack);
    hud->xp_bar = sfRectangleShape_create();
    sfRectangleShape_setSize(hud->xp_bar, (sfVector2f){29, 4});
    sfRectangleShape_setFillColor(hud->xp_bar, sfBlue);
    return hud;
}

void display_hud(sfRenderWindow *window, hud_t *hud)
{
    sfRenderWindow_drawRectangleShape(window, hud->health_back, NULL);
    sfRenderWindow_drawRectangleShape(window, hud->health_bar, NULL);
    sfRenderWindow_drawRectangleShape(window, hud->xp_back, NULL);
    sfRenderWindow_drawRectangleShape(window, hud->xp_bar, NULL);
}

void update_stats(entity_t *player)
{
    int lvl = player->xp / 100;

    player->dmg = 50 + (10 * lvl);
    player->max_hp = 300 + (10 * lvl);
}

void update_xp_bar(int xp, hud_t *hud, sfView *view)
{
    double new_size = 0;
    sfVector2f view_center = sfView_getCenter(view);

    xp = xp % 100;
    new_size = (xp * 29) / 100;
    sfRectangleShape_setSize(hud->xp_bar, (sfVector2f){new_size, 4});
    sfRectangleShape_setPosition(hud->xp_back,
    (sfVector2f){view_center.x - 110, view_center.y - 53});
    sfRectangleShape_setPosition(hud->xp_bar,
    (sfVector2f){view_center.x - 109.5, view_center.y - 52.5});
}

void update_health_bar(int health, int hp_max,
        hud_t *hud, sfView *view)
{
    double new_size = 0;
    sfVector2f view_center = sfView_getCenter(view);

    if (health < 0)
        health = 0;
    if (health > hp_max)
        health = hp_max;
    new_size = (health * 29) / hp_max;
    sfRectangleShape_setSize(hud->health_bar, (sfVector2f){new_size, 4});
    sfRectangleShape_setPosition(hud->health_back,
    (sfVector2f){view_center.x - 110, view_center.y - 60});
    sfRectangleShape_setPosition(hud->health_bar,
    (sfVector2f){view_center.x - 109.5, view_center.y - 59.5});
}
