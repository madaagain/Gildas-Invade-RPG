/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** save
*/

#include "gamestate.h"
#include "save.h"
#include <stdio.h>

char *my_itoa(int nb)
{
    int i = 0;
    int tmp = nb;
    char *str = malloc(sizeof(char) * 100);
    for (i = 0; tmp > 0; i++) {
        tmp /= 10;
    }
    str[i] = '\0';
    for (i = i - 1; i >= 0; i--) {
        str[i] = nb % 10 + '0';
        nb /= 10;
    }
    return (str);
}

char *write_number_to_buffer(int nb, char *buffer)
{
    int i = 0;
    for (i = 0; buffer[i] != '\0'; i++);
    char *number = my_itoa(nb);
    for (int j = 0; number[j] != '\0'; j++, i++)
        buffer[i] = number[j];
    buffer[i] = '\n';
    buffer[i + 1] = '\0';
    free(number);
    return (buffer);
}

void write_save(gamestate_t *gamestate)
{
    char *buffer = malloc(sizeof(char) * 100);
    int fd = open("save.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1)
        return;
    buffer[0] = '\0';
    write_number_to_buffer(gamestate->player->pos.x, buffer);
    write_number_to_buffer(gamestate->player->pos.y, buffer);
    write_number_to_buffer(gamestate->player->xp, buffer);
    write_number_to_buffer(gamestate->player->max_hp, buffer);
    write_number_to_buffer(gamestate->player->hp, buffer);
    write_number_to_buffer(gamestate->level, buffer);
    write_number_to_buffer(gamestate->floor, buffer);
    write(fd, buffer, my_strlen(buffer));
    free(buffer);
}

char* do_getline(FILE *stream)
{
    size_t size = 0;
    char *buffer2 = NULL;

    getline(&buffer2, &size, stream);
    return buffer2;
}

gamestate_t *read_save(char *filepath, gamestate_t *gamestate)
{
    FILE *stream = fopen(filepath, "r");
    char *buffer = NULL;
    size_t size = 0;
    gamestate->is_end = 0;
    getline(&buffer, &size, stream);
    gamestate->player->pos.x = str_to_int(buffer);
    buffer = do_getline(stream);
    gamestate->player->pos.y = str_to_int(buffer);
    buffer = do_getline(stream);
    gamestate->player->xp = str_to_int(buffer);
    buffer = do_getline(stream);
    gamestate->player->max_hp = str_to_int(buffer);
    buffer = do_getline(stream);
    gamestate->player->hp = str_to_int(buffer);
    buffer = do_getline(stream);
    gamestate->level = str_to_int(buffer);
    buffer = do_getline(stream);
    gamestate->floor = str_to_int(buffer);
    gamestate->player->alive = 1;
    return gamestate;
}
