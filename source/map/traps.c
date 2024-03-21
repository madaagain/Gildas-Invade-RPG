/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** traps
*/

#include "map.h"
#include "gamestate.h"

static int assign_trap_type(int type)
{
    if (type == 58)
        return 57;
    if (type == 57)
        return 56;
    if (type == 56)
        return 55;
    if (type == 55)
        return 58;
    return (type);
}

static int assign_torch_type(int type)
{
    if ((type >= 1 && type <= 3) || (type >= 5 && type <= 7) ||
        (type >= 9 && type <= 11) || (type >= 13 && type <= 15)
        || (type >= 17 && type <= 19))
        return (type + 1);
    if (type == 4 || type == 8 || type == 12 || type == 16 || type == 20)
        return (type - 3);
    return (type);
}

static void animate_all_traps(layer_t *layers)
{
    for (int i = 0; layers[3].tiles[i]; i++)
        for (int j = 0; layers[3].tiles[i][j].type != -1; j++)
            layers[3].tiles[i][j].type =
            assign_trap_type(layers[3].tiles[i][j].type);
}

static void animate_all_torches(layer_t *layers)
{
    for (int i = 0; layers[2].tiles[i]; i++)
        for (int j = 0; layers[2].tiles[i][j].type != -1; j++)
            layers[2].tiles[i][j].type =
            assign_torch_type(layers[2].tiles[i][j].type);
}

void animate_traps(layer_t *layers, gamestate_t *gamestate)
{
    sfTime time = sfClock_getElapsedTime(gamestate->trap_clock);
    sfTime torchtime = sfClock_getElapsedTime(gamestate->torch_clock);
    float timer = sfTime_asSeconds(time);
    float torch_timer = sfTime_asSeconds(torchtime);

    if (torch_timer >= 0.25) {
        animate_all_torches(layers);
        sfClock_restart(gamestate->torch_clock);
    }
    if (timer >= 0.5) {
        gamestate->count_down += 1;
        if (gamestate->count_down == 4) {
            gamestate->count_down = 0;
            sfSound_play(gamestate->sounds[4]);
        }
        animate_all_traps(layers);
        sfClock_restart(gamestate->trap_clock);
    }
}
