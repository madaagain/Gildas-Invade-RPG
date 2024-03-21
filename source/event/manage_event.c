/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** manage_event
*/

#include "gamestate.h"
#include "event.h"
#include "npc.h"
#include "fight.h"
#include "ig_menu.h"
#include "view.h"

void zoom_view(gamestate_t *gamestate, entity_t *player, layer_t *layers)
{
    sfView_zoom(gamestate->view, gamestate->zoom);
    sfView_setCenter(gamestate->view, refresh_view(player, gamestate->view,
        layers[0]));
    sfRenderWindow_setView(gamestate->window, gamestate->view);
}

static void manage_zoom(gamestate_t **gamestate, entity_t *player,
    layer_t *layers)
{
    if ((*gamestate)->event->key.code == sfKeyA &&
    (*gamestate)->is_zoomed) {
        (*gamestate)->zoom = 1.0 / 1.25 ;
        (*gamestate)->is_zoomed = 0;
        zoom_view(*gamestate, player, layers);
    }
    if ((*gamestate)->event->key.code == sfKeyR &&
    !(*gamestate)->is_zoomed) {
        (*gamestate)->zoom = 1.25;
        (*gamestate)->is_zoomed = 1;
        zoom_view(*gamestate, player, layers);
    }
}

layer_t *key_pressed(gamestate_t **gamestate, PLAYER, layer_t *layers, MOBS)
{
    if ((*gamestate)->event->key.code == sfKeyE)
        layers = interact(player, layers, gamestate, mobs);
    if ((*gamestate)->event->key.code == sfKeySpace) {
        attack(player, *mobs);
        sfSound_play((*gamestate)->sounds[3]);
    }
    if ((*gamestate)->event->key.code == sfKeyF)
        *mobs = kill_mob(*mobs, *mobs);
    if ((*gamestate)->event->key.code == sfKeyC)
        *mobs = add_node(*mobs, 50.0, 50.0, rand() % 12);
    manage_zoom(gamestate, player, layers);
    get_move(player);
    return (layers);
}

void game_event(gamestate_t *gamestate, ig_menu_t *ig_menu,
            menu_t *menu, int *stat)
{
    update_stats(gamestate->player);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        *stat = start_ig_menu(gamestate, ig_menu, menu, gamestate->player);
    if (gamestate->player->alive == 0) {
        display_game_over(gamestate->window, menu->game_over, 0);
        *stat = 1;
    }
    if (gamestate->is_end == 1) {
        display_game_over(gamestate->window, menu->game_over, 1);
        *stat = 1;
    }
}

layer_t *manage_event(gamestate_t **gamestate, PLAYER, layer_t *layers, MOBS)
{
    while (sfRenderWindow_pollEvent((*gamestate)->window,
    (*gamestate)->event)) {
        if ((*gamestate)->event->type == sfEvtClosed)
            sfRenderWindow_close((*gamestate)->window);
        if ((*gamestate)->event->type == sfEvtKeyReleased)
            get_release(player, (*gamestate)->event);
        if ((*gamestate)->event->type == sfEvtKeyPressed)
            layers = key_pressed(gamestate, player, layers, mobs);
    }
    return (layers);
}
