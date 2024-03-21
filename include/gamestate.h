/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** window include
*/

#ifndef WINDOW_H
    #define WINDOW_H

    #include "map.h"
    #include "graphical.h"
    #include <fcntl.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <stdlib.h>
    #include "player.h"
    #include "npc.h"

    typedef struct gamestate_s {
        int count_down;
        sfSound **sounds;
        sfSoundBuffer **sound_buffer;
        sfMusic *music;
        sfClock *trap_clock;
        sfClock *torch_clock;
        sfRenderWindow *window;
        sfVideoMode video_mode;
        sfClock *anim;
        sfTime time;
        sfEvent *event;
        sfVector2f mouse_pos;
        sfVector2f mouse_pos_view;
        sfView *view;
        int is_zoomed;
        float zoom;
        int is_end;
        sfVector2f view_pos;
        sfVector2f view_size;
        sfVector2f view_center;
        entity_t *player;
        npc_t *mobs;
        int level;
        int floor;
    } gamestate_t;

    gamestate_t *initalise_gamestate(void);

    /* traps */
    void animate_traps(layer_t *layers, gamestate_t *gamestate);
    void destroy_gamestate(gamestate_t *gamestate);

    /* animation_npc.c */
    void animate_entities(entity_t *player, npc_t *mobs,
    gamestate_t *gamestate);
    /*management_npc*/
    void npc_management(gamestate_t *gamestate,
    npc_t **mobs, layer_t *layers, entity_t *player);
    npc_t *reload_mobs(gamestate_t **gamestate);

    /* save */
    void write_save(gamestate_t *gamestate);
    gamestate_t *read_save(char *filepath, gamestate_t *gamestate);
#endif /* !WINDOW_H */
