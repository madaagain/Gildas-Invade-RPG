/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** get_level_path
*/

#include "my.h"

char *get_level_path(char *level, char *floor, int type)
{
    char walls[6][100] = {"walls", "floor", "interactible",
    "deco", "keys", "mobs"};
    char *path = my_strdup("ressources/level");
    path = my_strcat(path, level);
    path = my_strcat(path, "/");
    path = my_strcat(path, floor);
    path = my_strcat(path, "/");
    path = my_strcat(path, walls[type]);
    path = my_strcat(path, ".txt");
    return (path);
}
