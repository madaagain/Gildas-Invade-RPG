/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** event
*/

#ifndef EVENT_H_
    #define EVENT_H_

    #define EVENT sfEvent *event
    #define WINDOW sfWindow *window
    #define PLAYER entity_t *player
    #define MOBS npc_t **mobs
    #define GAMESTATE gamestate_t *gamestate

    #include "graphical.h"
    #include "player.h"
    #include "npc.h"
    #include "map.h"
    #include "gamestate.h"
    #include "menu.h"

    /* door.c */
    int is_locked_door(int type);
    int is_open_door(int type);
    int is_unlocked_door(int type);
    void unlock_door(layer_t *layers, sfVector2i closest_door);
    void open_close_door(layer_t *layers, sfVector2i pos,
    gamestate_t *gamestate);
    sfVector2i find_closest_door(layer_t *layers, sfVector2i pos);
    sfVector2i find_adjacent_door(layer_t *layers, sfVector2i pos);

    /* interact.c */
    layer_t *interact(
    entity_t *player,layer_t *layers, gamestate_t **gamestate,
    npc_t **mobs);

    /* manage_event.c */
    layer_t *manage_event(gamestate_t **gamestate,
    PLAYER, layer_t *layers, MOBS);
    void game_event(gamestate_t *gamestate, ig_menu_t *ig_menu,
            menu_t *menu, int *stat);
    sfVector2i get_closest_tile(entity_t *player);
    void get_chest_event(PLAYER, layer_t *layers, gamestate_t **gamestate);

#endif /* !EVENT_H_ */
