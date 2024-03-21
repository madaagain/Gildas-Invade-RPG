/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** destroy gamestate
*/

#include "gamestate.h"

void destroy_gamestate(gamestate_t *gamestate)
{
    sfMusic_stop(gamestate->music);
    sfMusic_destroy(gamestate->music);
    for (int i = 0; i < 5; i++)
        sfSound_destroy(gamestate->sounds[i]);
    for (int i = 0; i < 5; i++)
        sfSoundBuffer_destroy(gamestate->sound_buffer[i]);
    sfClock_destroy(gamestate->anim);
    sfClock_destroy(gamestate->trap_clock);
    sfClock_destroy(gamestate->torch_clock);
    sfRenderWindow_destroy(gamestate->window);
    free(gamestate->event);
    free(gamestate);
}
