/*
** EPITECH PROJECT, 2023
** RPG
** File description:
** view
*/

#include "view.h"


sfView *init_view(entity_t *player)
{
    sfView *view = sfView_create();
    sfView_setSize(view, (sfVector2f){15 * 16, 8 * 16});
    sfView_setCenter(view, player->pos);
    return view;
}

sfVector2f refresh_view(entity_t *player, sfView *view, layer_t layer)
{
    sfView_setCenter(view, (sfVector2f) {player->pos.x + 8, player->pos.y + 8});
    sfVector2f pos = sfView_getCenter(view);
    sfVector2f size = sfView_getSize(view);
    sfVector2f m_size = {layer.size.x * 16, layer.size.y * 16};
    if (pos.x - (size.x / 2) <= 0)
        pos.x = (size.x / 2);
    if (pos.x + (size.x / 2) >= m_size.x)
        pos.x = (m_size.x - (size.x / 2));
    if (pos.y - (size.y / 2) <= 0)
        pos.y = (size.y / 2);
    if (pos.y + (size.y / 2) >= m_size.y)
        pos.y = (m_size.y - (size.y / 2));
    return pos;
}
