/*
** EPITECH PROJECT, 2023
** init button
** File description:
** rpg
*/

#include "gamestate.h"
#include "menu.h"
#include <stdlib.h>

void init_new_button(menu_button_t *button, sfFont *font,
                    char *str, sfVector2f button_pos)
{
    sfVector2f button_size = {180, 60};
    sfText* text = sfText_create();

    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setFillColor(text, sfMagenta);
    sfText_setCharacterSize(text, 30);
    button->button = sfRectangleShape_create();
    sfRectangleShape_setSize(button->button, button_size);
    sfRectangleShape_setPosition(button->button, button_pos);
    sfRectangleShape_setFillColor(button->button, sfBlack);
    sfRectangleShape_setOutlineColor(button->button, sfRed);
    sfRectangleShape_setOutlineThickness(button->button, 2);
    button->text = text;
    button->state = BASIC;
}

menu_button_t *init_buttons(void)
{
    menu_button_t *buttons = (menu_button_t*)malloc(sizeof(menu_button_t) * 4);
    sfFont *font = sfFont_createFromFile("ressources/font/Roboto.ttf");

    init_new_button(&buttons[NEW], font,
    "NEW", (sfVector2f){680, 460});
    init_new_button(&buttons[LOAD], font,
    "LOAD", (sfVector2f){1080, 460});
    init_new_button(&buttons[OPTIONS], font,
    "OPTIONS", (sfVector2f){680, 600});
    init_new_button(&buttons[QUIT], font,
    "QUIT", (sfVector2f){1080, 600});
    for (int i = 0; i < 4; ++i) {
        sfText_setColor(buttons[i].text, sfRed);
        sfRectangleShape_setFillColor(buttons[i].button, sfBlack);
    }
    return buttons;
}
