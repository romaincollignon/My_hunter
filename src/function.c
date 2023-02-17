/*
** EPITECH PROJECT, 2022
** periph.c
** File description:
** save touch periph
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/Window/Event.h>
#include <time.h>
#include <stdlib.h>

#include <../include/struct_menu.h>
#include <../include/my.h>

int my_random(int min, int max)
{
    srand(time(NULL));
    int tmp = rand();
    int tmp_result = tmp % max + min;
    return tmp_result;
}

int function_sprite_cb(sfRenderWindow* window, int tmp)
{
    sfIntRect rect;
    ps position = {0, 0};
    rect.left = 100;
    rect.top = 40;
    rect.width = 75;
    rect.height = 75;
    int tmp_sprite = 0;
    sfTexture* corbeau01 = sfTexture_createFromFile("./res/corbeau_sheet.png", \
        &rect);
    sfSprite* sprite_cb01 = sfSprite_create();
    sfVector2f cb01_scale = {1.5, 1.5};
    position.pos_x_01 = 0;
    sfSprite_setTexture(sprite_cb01, corbeau01, sfTrue);
    sfSprite_setScale(sprite_cb01, cb01_scale);
    sfVector2f cb01_pos = {position.pos_x_01, 500};
    sfSprite_setPosition(sprite_cb01, cb01_pos);
    sfRenderWindow_drawSprite(window, sprite_cb01, NULL);
    sfRenderWindow_display(window);
    return tmp;
}

int my_destroy(sfSprite *sprite, sfTexture *texture)
{
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    return 0;
}

int my_destroy_game(sfSprite *sprite, sfTexture *texture, i_txt *info_txt,\
ds *display)
{
    sfFont_destroy(info_txt->font_01);
    sfFont_destroy(info_txt->font_02);
    sfText_destroy(info_txt->txt_01);
    sfText_destroy(info_txt->txt_02);
    sfTexture_destroy(display->fond_game);
    sfFont_destroy(display->font_01_s_t);
    sfText_destroy(display->text_01_s_t);
    sfFont_destroy(display->font_02_s_t);
    sfText_destroy(display->text_02_s_t);
    sfFont_destroy(display->font_03_s_b);
    sfText_destroy(display->text_03_s_b);
    sfFont_destroy(display->font_04_s_b);
    sfText_destroy(display->text_04_s_b);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    return 0;
}

int verif_pos_bird(sfRenderWindow* window, ps *position, sfEvent event)
{
    int *zone[] = {position->pos_x_01, (position->pos_x_01) + 90,
    position->pos_y_01, (position->pos_y_01) + 90};
    if (mw2(zone, window) == 1) {
        if (event.type == sfEvtMouseButtonPressed) {
            return 1;
        }
    }
    return 0;
}
