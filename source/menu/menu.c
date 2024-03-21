/*
** EPITECH PROJECT, 2023
** menu
** File description:
** rpg
*/

#include "gamestate.h"
#include "menu.h"
#include "ig_menu.h"
#include <stdlib.h>
#include "player.h"

void display_buttons(sfRenderWindow *window, menu_button_t *buttons, int nb)
{
    for (int i = 0; i < nb; ++i) {
        sfRenderWindow_drawRectangleShape(window, buttons[i].button, NULL);
        sfRenderWindow_drawText(window, buttons[i].text, NULL);
    }
}

void display_menu(menu_button_t *buttons, sfRenderWindow *window, menu_t *menu)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, menu->background, NULL);
    display_buttons(window, buttons, 4);
    sfRenderWindow_display(window);
}

void reset_player(entity_t *player, gamestate_t *gamestate)
{
    player->hp = 300;
    player->max_hp = 300;
    player->alive = 1;
    player->xp = 0;
    player->dmg = 50;
    player->pos = (sfVector2f){60, 48};
    gamestate->is_end = 0;
    gamestate->level = 1;
    gamestate->floor = 1;
}

void handle_menu_buttons(gamestate_t *gamestate, menu_t *menu,
    ig_menu_t *ig_menu, npc_t *mobs)
{
    menu_button_t *buttons = menu->buttons;
    sfRenderWindow *window = gamestate->window;

    if (buttons[0].state == CLICK) {
        reset_player(gamestate->player, gamestate);
        run_game(menu, ig_menu, gamestate, mobs);
    }
    if (buttons[1].state == CLICK) {
        read_save("save.txt", gamestate);
        run_game(menu, ig_menu, gamestate, mobs);
    }
    if (buttons[2].state == CLICK) {
        run_options(menu, gamestate);
    }
    if (buttons[3].state == CLICK) {
        sfRenderWindow_close(window);
    }
    update_bounds(buttons, window, 4);
}

void run_menu(gamestate_t *gamestate, menu_t *menu,
    ig_menu_t *ig_menu, npc_t *mobs)
{
    sfEvent event;
    sfRenderWindow *window = gamestate->window;
    menu_button_t *buttons = menu->buttons;

    sfRenderWindow_setView(window, sfRenderWindow_getDefaultView(window));
    update_bounds(buttons, window, 4);
    update_text_pos(buttons, 4);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            handle_close_event(window, event);
        }
        update_states(buttons, window, 4);
        update_colors(buttons, sfBlack, 4);
        display_menu(buttons, window, menu);
        handle_menu_buttons(gamestate, menu, ig_menu, mobs);
    }
}
