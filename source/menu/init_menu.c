/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** init menu
*/

#include "gamestate.h"
#include "menu.h"

sfText *init_options_text(sfFont *font, sfText *text, char *str, double y)
{
    sfVector2f text_pos;
    sfFloatRect text_bounds;

    text = sfText_create();
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setFillColor(text, sfBlack);
    if (str[0] == 'O')
        sfText_setCharacterSize(text, 80);
    else
        sfText_setCharacterSize(text, 60);
    sfText_setStyle(text, sfTextUnderlined);
    text_bounds = sfText_getGlobalBounds(text);
    text_pos.x = 960 - (text_bounds.width) / 2.f;
    text_pos.y = y;
    sfText_setPosition(text, text_pos);
    return text;
}

void set_text(options_t *options)
{
    options->font = sfFont_createFromFile("ressources/font/options.ttf");
    options->options_text =
    init_options_text(options->font, options->options_text, "OPTIONS", 30);
    options->fps_text =
    init_options_text(options->font, options->fps_text, "FPS", 150);
    options->res_text =
    init_options_text(options->font, options->res_text, "RESOLUTION", 450);
    options->vol_text =
    init_options_text(options->font, options->vol_text, "VOLUME", 750);
}

void init_options(menu_t *menu, sfRenderWindow *window)
{
    options_t *options = malloc(sizeof(options_t));

    options->back_text =
    sfTexture_createFromFile("ressources/sprites/options_back.png", NULL);
    options->background = sfSprite_create();
    sfSprite_setTexture(options->background, options->back_text, sfTrue);
    sfSprite_setPosition(options->background, (sfVector2f){0, 0});
    options->text_back_arrow =
    sfTexture_createFromFile("ressources/sprites/back_arrow.png", NULL);
    options->back_arrow = sfSprite_create();
    sfSprite_setTexture(options->back_arrow, options->text_back_arrow, sfTrue);
    sfSprite_setScale(options->back_arrow, (sfVector2f){0.33, 0.33});
    sfSprite_setPosition(options->back_arrow, (sfVector2f){10, 10});
    set_text(options);
    init_opt_buttons(options, window);
    menu->options = options;
}

menu_t *init_menu(gamestate_t *gamestate)
{
    menu_button_t *buttons = init_buttons();
    menu_t *menu_info = malloc(sizeof(menu_t));

    menu_info->buttons = buttons;
    menu_info->back_text =
    sfTexture_createFromFile("ressources/sprites/background.png", NULL);
    menu_info->background = sfSprite_create();
    sfSprite_setTexture(menu_info->background, menu_info->back_text, sfTrue);
    sfSprite_setPosition(menu_info->background, (sfVector2f){0, 0});
    init_options(menu_info, gamestate->window);
    menu_info->game_over = init_game_over();
    return menu_info;
}
