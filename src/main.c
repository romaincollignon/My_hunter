/*
** EPITECH PROJECT, 2022
** main
** File description:
** main -> MY_HUNTER
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <time.h>

#include "struct_menu.h"
#include "my.h"

int bird(sfRenderWindow* window, ps *position, scr *score)
{
    static sfClock *tm = NULL;
    !tm ? tm = sfClock_create() : mini_printf("");
    if (position->pos_x_01 >= 1920)
        return 2;
    position->pos_x_01 = position->pos_x_01 + 5 * (score->tmp_score + 3) / 2.4;
    sfIntRect rect = {(sfClock_getElapsedTime(tm).microseconds / 50000) %
    9 * 91.1, 40, 91.1, 91.1};
    sfTexture* corbeau01 = sfTexture_createFromFile("./res/cb_shet.png", &rect);
    sfSprite* sprite_cb01 = sfSprite_create();
    sfVector2f cb01_scale = {0.9, 0.9};
    sfSprite_setTexture(sprite_cb01, corbeau01, sfTrue);
    sfSprite_setScale(sprite_cb01, cb01_scale);
    sfVector2f cb01_pos = {position->pos_x_01, position->pos_y_01};
    sfSprite_setPosition(sprite_cb01, cb01_pos);
    sfRenderWindow_drawSprite(window, sprite_cb01, NULL);
    sfTexture_destroy(corbeau01);
    sfSprite_destroy(sprite_cb01);
    return 0;
}

int main_bird(sfRenderWindow* window, scr *score, ps *position, sfEvent event)
{
    int a = 0;
    int tmp = 0;
    if (verif_pos_bird(window, position, event) == 1){
        tmp = 1;
        position->score++;
        score->tmp_score++;
        file_score(position->score);
    }
    if (tmp == 1) {
        int random = my_random(100, 890);
        position->pos_x_01 = -40;
        position->pos_y_01 = random;
        tmp = 0;
    }
    if (tmp == 0) {
        a = bird(window, position, score);
        if (a == 2)
            return a;
        return 0;
    } return tmp;
}

int main_game(sfRenderWindow* window, scr *score)
{
    ds *display = malloc(sizeof(ds));
    i_txt *info_txt = malloc(sizeof(i_txt));
    init(display, info_txt);
    ps position = {0, 0, 0, 0, 0, 0};
    sfSprite* sprite = sfSprite_create();
    sfEvent event;
    sfSprite_setTexture(sprite, display->fond_game, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event));
        sfRenderWindow_drawSprite(window, sprite, NULL);
        position.tmp_b = main_bird(window, score, &position, event);
        if (position.tmp_b == 2)
            return position.tmp_b;
        position.tmp_m = cherch_perif_game(window, event);
        if (position.tmp_m == 42 || position.tmp_m == 0 || position.tmp_b == 2)
            return position.tmp_m;
        display_all_game(window, position, info_txt, display);
        sfRenderWindow_drawText(window, display->text_01_s_t, NULL);
        sfRenderWindow_display(window);
    } return my_destroy_game(sprite, display->fond_game, info_txt, display);
}

int main_menu(sfRenderWindow* window, scr *score)
{
    sfTexture* texture = sfTexture_createFromFile("./res/fond_game.png", NULL);
    sfSprite* sprite;
    sfEvent event;
    int tmp = 0;
    if (!window)
        return EXIT_FAILURE;
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        tmp = cherch_perif(window, event);
        if (tmp == 42 || tmp == 1 || tmp == 3)
            return tmp;
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        display_all_menu(window);
        sfRenderWindow_display(window);
    }
    return my_destroy(sprite, texture);
}

int main(int ac, char **av, char **env)
{
    if (!env || !env[0])
        return 84;
    scr score = {0, 0};
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window = sfRenderWindow_create(mode, name(), sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        return printf_credit(0);
    verif_file() == 84 ? ac = 84 : mini_printf("");
    if (ac >= 2)
        return printf_error();
    for (int a = 0; sfRenderWindow_isOpen(window); ) {
        a == 0 ? a = main_menu(window, &score) : 0;
        a == 1 ? score.tmp_score = 0 : 0;
        a = a == 1 ? main_game(window, &score) : a;
        a == 2 ? a = main_pause(window, &score) : 0;
        a == 3 ? a = main_credit(window, &score) : 0;
        a == 42 ? sfRenderWindow_close(window) : 0;
    } sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}
