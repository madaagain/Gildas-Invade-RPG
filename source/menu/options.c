/*
** EPITECH PROJECT, 2023
** menu rpg
** File description:
** options
*/

#include "gamestate.h"
#include "menu.h"


void start_how_to_play(sfRenderWindow *window, sfFont *font)
{
    sfText* text = sfText_create();
    sfEvent event;

    sfText_setFont(text, font);
    sfText_setCharacterSize(text , 50);
    sfText_setString(text, "Z: up\nQ: left\nS: down\n\
D: right\nSpace_bar: attack\nEscape: quit/menu\nR: dezoom\n\
A: zoom\nE: interact\n\n[ADMIN]\nC: spawn mob\nF: kill mob\n");
    sfText_setPosition(text, (sfVector2f){1,100});
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            handle_close_event(window, event);
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            break;
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawText(window, text, NULL);
        sfRenderWindow_display(window);
    }
}

void handle_close_event(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

int go_back_to_menu(sfRenderWindow *window, options_t *options)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    if (sfFloatRect_contains(&(options->arrow_bounds), mouse_pos.x, mouse_pos.y)
        && sfMouse_isButtonPressed(sfMouseLeft)) {
        return 1;
    }
    return 0;
}

void display_options(sfRenderWindow *window, options_t *options)
{
    sfRenderWindow_drawSprite(window, options->background, NULL);
    sfRenderWindow_drawText(window, options->options_text, NULL);
    sfRenderWindow_drawText(window, options->fps_text, NULL);
    sfRenderWindow_drawText(window, options->res_text, NULL);
    sfRenderWindow_drawText(window, options->vol_text, NULL);
    display_buttons(window, options->res_buttons, 3);
    display_buttons(window, options->fps_buttons, 3);
    display_buttons(window, options->vol_buttons, 2);
    sfRenderWindow_drawSprite(window, options->back_arrow, NULL);
}

void run_options(menu_t *menu, gamestate_t *gamestate)
{
    sfRenderWindow *window = gamestate->window;
    sfEvent *event = gamestate->event;
    options_t *options = menu->options;

    update_all_bounds(window, options);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, event))
            handle_close_event(window, *event);
        if (go_back_to_menu(window, options) == 1 ||
            sfKeyboard_isKeyPressed(sfKeyEscape)) {
            sfSleep(sfSeconds(0.2));
            break;
        }
        resize_window(window, options);
        change_fps(window, options);
        update_all_buttons(window, options);
        sfRenderWindow_clear(window, sfBlack);
        display_options(window, options);
        sfRenderWindow_display(window);
    }
}
