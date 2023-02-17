/*
** EPITECH PROJECT, 2022
** display_txt.c
** File description:
** display text
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include "struct_menu.h"
#include "my.h"

sfVector2f get_position(int x, int y)
{
    sfVector2f vector;
    vector.y = y;
    vector.x = x;
    return vector;
}

void display_txt_title(sfRenderWindow* n_window, char *txt, int x, int y)
{
    sfText* text;
    sfFont* font;
    font = sfFont_createFromFile("./res/Bostana.ttf");
    text = sfText_create();
    sfText_setString(text, txt);
    sfText_setPosition(text, get_position(x, y));
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 100);
    sfText_setColor(text, sfBlack);
    sfRenderWindow_drawText(n_window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}

void display_txt_basic(sfRenderWindow* n_window, char *txt, int x, int y)
{
    sfText* text;
    sfFont* font;
    font = sfFont_createFromFile("./res/Play_Pretend.otf");
    text = sfText_create();
    sfText_setString(text, txt);
    sfText_setPosition(text, get_position(x, y));
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfRenderWindow_drawText(n_window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}

void display_txt_score(sfRenderWindow* n_window, char *txt, i_txt *info_txt)
{
    sfText* text;
    sfFont* font;
    font = sfFont_createFromFile("./res/Play_Pretend.otf");
    text = sfText_create();
    sfText_setString(text, txt);
    sfText_setPosition(text, get_position(info_txt->x_01, info_txt->y_01));
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfRenderWindow_drawText(n_window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}

void display_txt_score_int(sfRenderWindow* n_window, char *score_m, \
    i_txt *info_txt)
{
    sfText* text = sfText_create();
    sfFont* font = sfFont_createFromFile("./res/Play_Pretend.otf");
    sfText_setString(text, score_m);
    sfText_setPosition(text, get_position(info_txt->x_02, info_txt->y_02));
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfRenderWindow_drawText(n_window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}
