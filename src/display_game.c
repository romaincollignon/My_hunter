/*
** EPITECH PROJECT, 2022
** display_game.c
** File description:
** display game
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include "struct_menu.h"
#include "my.h"

void display_game_01(sfRenderWindow* n_window, char *txt, i_txt *info_txt)
{
    sfText* text;
    sfFont* font;
    font = sfFont_createFromFile("./res/CodeNext.ttf");
    text = sfText_create();
    sfText_setString(text, txt);
    sfText_setPosition(text, get_position(info_txt->x_03, info_txt->y_03));
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfRenderWindow_drawText(n_window, text, NULL);
}

void display_game_02(sfRenderWindow* n_window, char *txt, i_txt *info_txt)
{
    sfText* text;
    sfFont* font;
    font = sfFont_createFromFile("./res/CodeNext.ttf");
    text = sfText_create();
    sfText_setString(text, txt);
    sfText_setPosition(text, get_position(info_txt->x_04, info_txt->y_04));
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfRenderWindow_drawText(n_window, text, NULL);
}

static void init2(i_txt *info_txt)
{
    info_txt->x_01 = 5;
    info_txt->y_01 = 0;
    info_txt->x_02 = 230;
    info_txt->y_02 = 0;
    info_txt->x_03 = 1730;
    info_txt->y_03 = 980;
    info_txt->x_04 = 1845;
    info_txt->y_04 = 950;
}

void init(ds *display, i_txt *info_txt, ps *position)
{
    init2(info_txt);
    ds tmp2;
    info_txt->font_01 = sfFont_createFromFile("./res/CodeNext.ttf");
    info_txt->txt_01 = sfText_create();
    info_txt->font_02 = sfFont_createFromFile("./res/CodeNext.ttf");
    info_txt->txt_02 = sfText_create();
    display->fond_game = sfTexture_createFromFile("./res/fond_map.png", NULL);
    display->font_01_s_t = sfFont_createFromFile("./res/Play_Pretend.otf");
    display->text_01_s_t = sfText_create();
    display->font_02_s_t = sfFont_createFromFile("./res/Play_Pretend.otf");
    display->text_02_s_t = sfText_create();
    display->font_03_s_b = sfFont_createFromFile("./res/Play_Pretend.otf");
    display->text_03_s_b = sfText_create();
    display->font_04_s_b = sfFont_createFromFile("./res/Play_Pretend.otf");
    display->text_04_s_b = sfText_create();
}
