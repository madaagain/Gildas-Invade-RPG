/*
** EPITECH PROJECT, 2023
** init ig menu
** File description:
** rpg
*/

#include "gamestate.h"
#include "ig_menu.h"
#include "menu.h"

static const sfIntRect text_rect[] = {{32, 64, 16, 16},
                                    {0, 0, 16, 16},
                                    {32, 48, 16, 16},
                                    {16, 48, 16, 16}};

void init_ig_menu_sprites(ig_menu_t *ig_menu)
{
    ig_menu->stats_text =
    sfTexture_createFromFile("ressources/sprites/rpg-items.png", NULL);
    ig_menu->stats_sprite = malloc(sizeof(sfSprite*) * 4);
    ig_menu->stats_txt = malloc(sizeof(sfText*) * 4);
    ig_menu->font = sfFont_createFromFile("ressources/font/Roboto.ttf");
    for (int i = 0; i < 4; ++i) {
        ig_menu->stats_sprite[i] = sfSprite_create();
        sfSprite_setTexture(ig_menu->stats_sprite[i],
                        ig_menu->stats_text, sfTrue);
        sfSprite_setTextureRect(ig_menu->stats_sprite[i], text_rect[i]);
        sfSprite_setPosition(ig_menu->stats_sprite[i],
                        (sfVector2f){550, 150 + (i * 100)});
        sfSprite_setScale(ig_menu->stats_sprite[i], (sfVector2f){6, 6});
        ig_menu->stats_txt[i] = sfText_create();
        sfText_setFont(ig_menu->stats_txt[i], ig_menu->font);
        sfText_setColor(ig_menu->stats_txt[i], sfBlack);
        sfText_setCharacterSize(ig_menu->stats_txt[i], 40);
        sfText_setPosition(ig_menu->stats_txt[i],
        (sfVector2f){660, 150 + (i * 100) + 20});
    }
}

ig_menu_t *init_ig_menu(sfRenderWindow *window)
{
    ig_menu_t *ig_menu = malloc(sizeof(ig_menu_t));
    menu_button_t *buttons = malloc(sizeof(menu_button_t) * 4);
    sfFont *font = sfFont_createFromFile("ressources/font/Roboto.ttf");

    ig_menu->back_text =
    sfTexture_createFromFile("ressources/sprites/options_back.png", NULL);
    ig_menu->background = sfSprite_create();
    sfSprite_setTexture(ig_menu->background, ig_menu->back_text, sfTrue);
    sfSprite_setPosition(ig_menu->background, (sfVector2f){500, 100});
    sfSprite_setScale(ig_menu->background, (sfVector2f){0.5, 0.6});
    init_new_button(&buttons[SAVE], font, "SAVE", (sfVector2f){550, 550});
    init_new_button(&buttons[OPTIONS_IG], font,
    "OPTIONS", (sfVector2f){550, 650});
    init_new_button(&buttons[LOAD_IG], font, "LOAD", (sfVector2f){550, 750});
    init_new_button(&buttons[MENU], font, "MENU", (sfVector2f){550, 850});
    ig_menu->buttons = buttons;
    update_bounds(ig_menu->buttons, window, 4);
    update_text_pos(ig_menu->buttons, 4);
    init_ig_menu_sprites(ig_menu);
    return ig_menu;
}
