/*
** EPITECH PROJECT, 2023
** init opt buttons
** File description:
** rpg
*/

#include "menu.h"
#include "gamestate.h"
#include <stdlib.h>

void init_res_buttons(options_t *options, sfRenderWindow *window)
{
    menu_button_t *buttons = (menu_button_t*)malloc(sizeof(menu_button_t) * 3);

    init_new_button(&buttons[0], options->font,
    "960*540", (sfVector2f){200, 550});
    init_new_button(&buttons[1], options->font,
    "1440*910", (sfVector2f){700, 550});
    init_new_button(&buttons[2], options->font,
    "1920*1080", (sfVector2f){1200, 550});
    update_bounds(buttons, window, 3);
    update_text_pos(buttons, 3);
    options->res_buttons = buttons;
}

void init_fps_buttons(options_t *options, sfRenderWindow *window)
{
    menu_button_t *buttons = (menu_button_t*)malloc(sizeof(menu_button_t) * 3);

    init_new_button(&buttons[0], options->font,
    "60 FPS", (sfVector2f){200, 250});
    init_new_button(&buttons[1], options->font,
    "90 FPS", (sfVector2f){700, 250});
    init_new_button(&buttons[2], options->font,
    "120 FPS", (sfVector2f){1200, 250});
    update_bounds(buttons, window, 3);
    update_text_pos(buttons, 3);
    options->fps_buttons = buttons;
}

void init_vol_buttons(options_t *options, sfRenderWindow *window)
{
    menu_button_t *buttons = (menu_button_t*)malloc(sizeof(menu_button_t) * 2);

    init_new_button(&buttons[0], options->font,
    "VOL DOWN", (sfVector2f){200, 850});
    init_new_button(&buttons[1], options->font,
    "VOL UP", (sfVector2f){700, 850});
    update_bounds(buttons, window, 2);
    update_text_pos(buttons, 2);
    options->vol_buttons = buttons;
}

void init_opt_buttons(options_t *options, sfRenderWindow *window)
{
    init_res_buttons(options, window);
    init_fps_buttons(options, window);
    init_vol_buttons(options, window);
}
