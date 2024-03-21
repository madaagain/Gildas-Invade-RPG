/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** update options
*/

#include "gamestate.h"
#include "menu.h"

static const sfVector2u window_sizes[] = {{960,540},
                                        {1440, 810},
                                        {1920, 1080}};

static const int fps[] = {60, 90, 120};

void update_all_bounds(sfRenderWindow* window, options_t *options)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);
    double ratio_x = window_size.x / 1920.f;
    double ratio_y = window_size.y / 1080.f;

    update_bounds(options->res_buttons, window, 3);
    update_bounds(options->fps_buttons, window, 3);
    update_bounds(options->vol_buttons, window, 2);
    options->arrow_bounds = sfSprite_getGlobalBounds(options->back_arrow);
    options->arrow_bounds.left *= ratio_x;
    options->arrow_bounds.top *= ratio_y;
    options->arrow_bounds.width *= ratio_x;
    options->arrow_bounds.height *= ratio_y;
}

void update_all_buttons(sfRenderWindow *window, options_t *options)
{
    update_states(options->res_buttons, window, 3);
    update_colors(options->res_buttons, sfWhite, 3);
    update_states(options->fps_buttons, window, 3);
    update_colors(options->fps_buttons, sfWhite, 3);
    update_states(options->vol_buttons, window, 2);
    update_colors(options->vol_buttons, sfWhite, 2);
}

void resize_window(sfRenderWindow *window, options_t *options)
{
    for (int i = 0; i < 3; ++i) {
        if (options->res_buttons[i].state == CLICK) {
            sfRenderWindow_setSize(window, window_sizes[i]);
            update_all_bounds(window, options);
            sfSleep(sfSeconds(0.1));
        }
    }
}

void change_fps(sfRenderWindow *window, options_t *options)
{
    for (int i = 0; i < 3; ++i) {
        if (options->fps_buttons[i].state == CLICK) {
            sfRenderWindow_setFramerateLimit(window, fps[i]);
            sfSleep(sfSeconds(0.1));
        }
    }
}

void update_volume(void)
{
    return;
}
