/*
** EPITECH PROJECT, 2023
** save
** File description:
** rpg
*/

#ifndef SAVE_H_
    #define SAVE_H_

void write_save(gamestate_t *gamestate);
gamestate_t *read_save(char *filepath, gamestate_t *gamestate);
int str_to_int(char *str);

#endif /* SAVE_H_ */
