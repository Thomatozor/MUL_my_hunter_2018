/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** Main loop for a level of the game
*/
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System.h>
#include <unistd.h>
#include "my_hunter.h"

duck_t **init_ducks(int nb_ducks, sfRenderWindow *window);
void move_ducks(duck_t **duck, int nb_ducks, float time);
void display_ducks(sfRenderWindow *window, duck_t **ducks, int nb_duck);
int analyse_game_events(sfRenderWindow *window, sfEvent event, duck_t **duck, int nb_ducks);
void reset_dead_ducks(duck_t **duck, int nb_ducks, sfRenderWindow *window);
void reset_far_ducks(duck_t **ducks, int nb_ducks, sfRenderWindow *window);
void destroy_ducks(duck_t **ducks, int nb_ducks);
void end_game(duck_t **ducks, int nb_ducks, int score);
sfText *init_text(sfRenderWindow *window, int score);
void display_score(sfText *text, int score);

void run_game(sfRenderWindow *window, int nb_ducks)
{
    sfClock *clock = sfClock_create();
    sfTime time;
    float seconds = 0.0;
    sfEvent event;
    duck_t **ducks = init_ducks(nb_ducks, window);
    int close_game = 0;
    sfTexture *background = sfTexture_createFromFile("../ressources/Landscape.png", NULL);
    sfSprite *sprite = sfSprite_create();
    int score = 0;
    sfText *text = init_text(window, score);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        display_score(text, score);
        sfSprite_setTexture(sprite, background, sfTrue);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawText(window, text, NULL);
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        display_ducks(window, ducks, nb_ducks);
        move_ducks(ducks, nb_ducks, seconds);
        while (sfRenderWindow_pollEvent(window, &event))
            score += analyse_game_events(window, event, ducks, nb_ducks);
        reset_dead_ducks(ducks, nb_ducks, window);
        reset_far_ducks(ducks, nb_ducks, window);
        sfRenderWindow_display(window);
    }
    end_game(ducks, nb_ducks, score);
}
