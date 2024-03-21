/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** view
*/

#ifndef VIEW_H_
    #define VIEW_H_

    #include "player.h"
    #include "graphical.h"

    /*view.c */
    sfView *init_view(entity_t *player);
    sfVector2f refresh_view(entity_t *player, sfView *view, layer_t layer);

#endif /* !VIEW_H_ */
