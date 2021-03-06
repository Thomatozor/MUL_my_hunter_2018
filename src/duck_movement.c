/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** Functions to move the ducks
*/
#include <SFML/Graphics/Sprite.h>
#include "my_hunter.h"

void move_rect(duck_t *duck, float time)
{
    if (time - duck->prev_time_rect_moved > 0.1) {
        if (duck->rect.left < 220)
            duck->rect.left += 110;
        else
            duck->rect.left = 0;
        duck->prev_time_rect_moved = time;
    }
}

void move_duck(duck_t *duck, float time)
{
    sfVector2f offset;
    sfVector2f duck_pos = sfSprite_getPosition(duck->sprite);

    if (time - duck->prev_time_moved > 0.004 && duck->is_dead == 0) {
        offset.x = duck->speed * duck->direction;
        offset.y = 0.0;
        move_rect(duck, time);
        sfSprite_move(duck->sprite, offset);
        duck->prev_time_moved = time;
    }
    else if (time - duck->prev_time_moved > 0.002 && duck->is_dead == 1) {
        offset.x = 0;
        offset.y = 10.0;
        if (duck->direction == 1)
            sfSprite_setRotation(duck->sprite, 90);
        else
            sfSprite_setRotation(duck->sprite, 240);
        sfSprite_move(duck->sprite, offset);
        duck->prev_time_moved = time;
    }
}

void move_ducks(duck_t **ducks, int nb_ducks, float time)
{
    for (int i = 0; i < nb_ducks; i++)
        move_duck(ducks[i], time);
}
