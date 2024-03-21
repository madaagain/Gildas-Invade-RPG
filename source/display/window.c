/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** window
*/

#include "gamestate.h"
#include "npc.h"

static void initialise_the_sounds(gamestate_t *gamestate)
{
    gamestate->sounds = malloc(sizeof(sfSound *) * 5);
    for (int i = 0; i < 5; i++)
        gamestate->sounds[i] = sfSound_create();
    gamestate->sound_buffer = malloc(sizeof(sfSoundBuffer *) * 5);
    gamestate->sound_buffer[0] =
    sfSoundBuffer_createFromFile("ressources/sounds/LEVER.ogg");
    gamestate->sound_buffer[1] =
    sfSoundBuffer_createFromFile("ressources/sounds/OPEN_DOOR.ogg");
    gamestate->sound_buffer[2] =
    sfSoundBuffer_createFromFile("ressources/sounds/SHUT_DOOR.ogg");
    gamestate->sound_buffer[3] =
    sfSoundBuffer_createFromFile("ressources/sounds/SLASH.ogg");
    gamestate->sound_buffer[4] =
    sfSoundBuffer_createFromFile("ressources/sounds/SPIKE_TRAP.ogg");
    for (int i = 0; i < 5; i++) {
        sfSound_setBuffer(gamestate->sounds[i], gamestate->sound_buffer[i]);
        sfSound_setVolume(gamestate->sounds[i], 50);
    }
    sfSound_setVolume(gamestate->sounds[3], 100);
    gamestate->count_down = 0;
}

static void initialise_the_view(gamestate_t *gamestate)
{
    gamestate->view = sfView_create();
    gamestate->view_size = (sfVector2f) {2000, 1000};
    sfView_setSize(gamestate->view, gamestate->view_size);
    sfView_setCenter(gamestate->view, (sfVector2f) {500, 500});
    sfRenderWindow_setView(gamestate->window, gamestate->view);
    gamestate->is_zoomed = 0;
    gamestate->zoom = 1.0;

}

gamestate_t *initalise_gamestate(void)
{
    gamestate_t *gamestate = malloc(sizeof(gamestate_t));
    gamestate->event = malloc(sizeof(sfEvent));
    gamestate->video_mode = (sfVideoMode){1920, 1080, 120};
    gamestate->window = sfRenderWindow_create(gamestate->video_mode,
    "MyRPG", sfClose | sfResize, NULL);
    gamestate->torch_clock = sfClock_create();
    gamestate->trap_clock = sfClock_create();
    gamestate->anim = sfClock_create();
    gamestate->is_end = 0;
    sfRenderWindow_setFramerateLimit(gamestate->window, 60);
    gamestate->level = 1;
    gamestate->floor = 1;
    gamestate->mobs = load_mobs_from_file("ressources/level1/1/mobs.txt");
    gamestate->music =
    sfMusic_createFromFile("ressources/music/GAME_MUSIC.ogg");
    sfMusic_setLoop(gamestate->music, sfTrue);
    sfMusic_play(gamestate->music);
    initialise_the_sounds(gamestate);
    initialise_the_view(gamestate);
    return (gamestate);
}
