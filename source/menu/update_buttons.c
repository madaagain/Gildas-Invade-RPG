/*
** EPITECH PROJECT, 2023
** update button
** File description:
** rpg
*/

#include "gamestate.h"
#include "menu.h"

void update_bounds(menu_button_t *buttons, sfRenderWindow *window, int nb)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    double ratio_x = window_size.x / 1920.f;
    double ratio_y = window_size.y / 1080.f;

    for (int i = 0; i < nb; ++i) {
        buttons[i].button_bounds =
        sfRectangleShape_getGlobalBounds(buttons[i].button);
        buttons[i].button_bounds.left *= ratio_x;
        buttons[i].button_bounds.top *= ratio_y;
        buttons[i].button_bounds.width *= ratio_x;
        buttons[i].button_bounds.height *= ratio_y;
    }
}

void update_states(menu_button_t *buttons, sfRenderWindow *window, int nb)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    menu_button_t *button = NULL;

    for (int i = 0; i < nb; ++i) {
        button = &(buttons[i]);
        if (sfFloatRect_contains(&(button->button_bounds),
            mouse_pos.x, mouse_pos.y)) {
            button->state = HOVER;
        } else
            button->state = BASIC;
        if (button->state == HOVER &&
            sfMouse_isButtonPressed(sfMouseLeft))
            button->state = CLICK;
    }
}

void update_colors(menu_button_t *buttons, sfColor color, int nb)
{
    for (int i = 0; i < nb; ++i) {
        if (buttons[i].state == BASIC)
            sfRectangleShape_setFillColor(buttons[i].button, color);
        if (buttons[i].state == HOVER)
            sfRectangleShape_setFillColor(buttons[i].button, sfGreen);
        if (buttons[i].state == CLICK)
            sfRectangleShape_setFillColor(buttons[i].button, sfBlue);
    }
}

void update_text_pos(menu_button_t *buttons, int nb)
{
    sfFloatRect bounds;
    sfVector2f text_pos;
    sfFloatRect text_bounds;

    for (int i = 0; i < nb; ++i) {
        bounds = buttons[i].button_bounds;
        text_bounds = sfText_getGlobalBounds(buttons[i].text);
        text_pos.x = bounds.left + (bounds.width - text_bounds.width) / 2.f;
        text_pos.y = bounds.top + (text_bounds.height) / 2.f;
        sfText_setPosition(buttons[i].text, text_pos);
    }
}
