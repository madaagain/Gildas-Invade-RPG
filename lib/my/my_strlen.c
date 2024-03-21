/*
** EPITECH PROJECT, 2022
** Luan BOURBIER
** File description:
** my putstr
*/

int my_strlen(char const *str)
{
    int nb = 0;

    while (str[nb] != '\0')
        nb++;
    return nb;
}
