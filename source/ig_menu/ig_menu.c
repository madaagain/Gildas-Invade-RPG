/*
** EPITECH PROJECT, 2023
** ig menu
** File description:
** rpg
*/

#include "gamestate.h"
#include "ig_menu.h"
#include "menu.h"
#include "my.h"
#include "save.h"

void display_ig_menu(sfRenderWindow *window, ig_menu_t *ig_menu)
{
    sfRenderWindow_drawSprite(window, ig_menu->background, NULL);
    display_buttons(window, ig_menu->buttons, 4);
    for (int i = 0; i < 4; ++i) {
        sfRenderWindow_drawSprite(window, ig_menu->stats_sprite[i], NULL);
        sfRenderWindow_drawText(window, ig_menu->stats_txt[i], NULL);
    }
}

void handle_options_button(menu_t *menu, ig_menu_t *ig_menu,
                        gamestate_t *gamestate)
{
    sfRenderWindow *window = gamestate->window;

    if (ig_menu->buttons[OPTIONS_IG].state == CLICK) {
        run_options(menu, gamestate);
        update_bounds(ig_menu->buttons, window, 4);
        sfRenderWindow_clear(window, sfBlack);
    }
    if (ig_menu->buttons[SAVE].state == CLICK) {
        write_save(gamestate);
    }
    if (ig_menu->buttons[LOAD_IG].state == CLICK) {
        read_save("save.txt", gamestate);
    }
}

void update_ig_menu(ig_menu_t *ig_menu, menu_t *menu,
            sfRenderWindow *window, gamestate_t *gamestate)
{
    handle_options_button(menu, ig_menu, gamestate);
    update_states(ig_menu->buttons, window, 4);
    update_colors(ig_menu->buttons, sfWhite, 4);
    display_ig_menu(window, ig_menu);
    sfRenderWindow_display(window);
}

void update_txt(ig_menu_t *ig_menu, entity_t *player)
{
    char *text = NULL;

    text = int_to_str(player->hp);
    text = my_strcat(text, " / ");
    text = my_strcat(text, int_to_str(player->max_hp));
    sfText_setString(ig_menu->stats_txt[0], text);
    free(text);
    text = int_to_str(player->dmg);
    sfText_setString(ig_menu->stats_txt[1], text);
    free(text);
    text = int_to_str(player->silver_key);
    sfText_setString(ig_menu->stats_txt[2], text);
    free(text);
    text = int_to_str(player->gold_key);
    sfText_setString(ig_menu->stats_txt[3], text);
    free(text);
}

int start_ig_menu(gamestate_t *gamestate, ig_menu_t *ig_menu,
                menu_t *menu, entity_t *player)
{
    sfEvent event;
    sfRenderWindow *window = gamestate->window;

    sfRenderWindow_setView(window, sfRenderWindow_getDefaultView(window));
    update_bounds(ig_menu->buttons, window, 4);
    sfSleep(sfSeconds(0.3));
    while (sfRenderWindow_isOpen(window)) {
        update_txt(ig_menu, player);
        while (sfRenderWindow_pollEvent(window, &event)) {
            handle_close_event(window, event);
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfSleep(sfSeconds(0.3));
            return 0;
        }
        update_ig_menu(ig_menu, menu, window, gamestate);
        if (ig_menu->buttons[MENU].state == CLICK)
            return 1;
    }
    return 0;
}
