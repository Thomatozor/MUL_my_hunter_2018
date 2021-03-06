/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** Functions to display and refresh the ducks sprites
*/
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/RenderWindow.h>
#include "my_hunter.h"

void display_ducks(sfRenderWindow *window, duck_t **ducks, infos_t *game_infos, float time)
{
    int nb_ducks = game_infos->nb_ducks;

    reset_ducks(ducks, game_infos, window);
    move_ducks(ducks, nb_ducks, time);
    for (int i = 0; i < nb_ducks; i++) {
        sfSprite_setTexture(ducks[i]->sprite, ducks[i]->texture, sfTrue);
        sfSprite_setTextureRect(ducks[i]->sprite, ducks[i]->rect);
        sfRenderWindow_drawSprite(window, ducks[i]->sprite, NULL);
    }
}
