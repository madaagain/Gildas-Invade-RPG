/*
** EPITECH PROJECT, 2023
** ig menu
** File description:
** rpg
*/

#ifndef IG_MENU_H_
    #define IG_MENU_H_
    #include "menu.h"
    #include "gamestate.h"
    #include "npc.h"

typedef enum ig_buttons {
    SAVE,
    LOAD_IG,
    OPTIONS_IG,
    MENU
} ig_buttons_t;

typedef enum sprite_type {
    HP,
    DAMAGE,
    SILVER_KEY,
    GOLD_KEY
} sprite_type_t;

ig_menu_t *init_ig_menu(sfRenderWindow* window);
int start_ig_menu(gamestate_t *gamestate, ig_menu_t *ig_menu,
                menu_t *menu, entity_t *player);
void run_game(menu_t *menu, ig_menu_t *ig_menu, gamestate_t *gamestate,
npc_t *mobs);
char *int_to_str(int nb);
ig_menu_t *init_ig_menu(sfRenderWindow *window);

#endif /* IG_MENU_H_ */
