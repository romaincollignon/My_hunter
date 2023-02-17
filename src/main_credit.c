/*
** EPITECH PROJECT, 2022
** main_credit.c
** File description:
** main credit
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

#include <../include/struct_menu.h>
#include <../include/my.h>

void display_txt_title_credit(sfRenderWindow* n_window, char *txt, int x, int y)
{
    sfText* text;
    sfFont* font;
    font = sfFont_createFromFile("./res/Bostana.ttf");
    text = sfText_create();
    sfText_setString(text, txt);
    sfText_setPosition(text, get_position(x, y));
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 100);
    sfText_setColor(text, sfWhite);
    sfRenderWindow_drawText(n_window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}

int cherch_perif_credit(sfRenderWindow* w, sfEvent event)
{
    int *b1[] = {300, 520, 440, 480};
    int *b2[] = {300, 800, 340, 380};
    int *b3[] = {300, 520, 380, 440};
    sfEvent act;
    while (sfRenderWindow_pollEvent(w, &act)) {
        if (act.type == sfEvtClosed) {
            return 42;
        } if (act.type == sfEvtKeyPressed && act.key.code == sfKeyEscape) {
            return 42;
        } if (mw1(b1, w, event) == 1 && act.type == sfEvtMouseButtonPressed) {
            return 42;
        } if (mw1(b2, w, event) == 1 && act.type == sfEvtMouseButtonPressed) {
            return 1;
        } if (mw1(b3, w, event) == 1 && act.type == sfEvtMouseButtonPressed) {
            return 0;
        }
    } return 4;
}

void display_all_credit(sfRenderWindow* n_window)
{
    p_txt menu_pause_txt = {"CREDIT", "Menu", "Start the game", "Home", \
        "exit", "by Romain. COllignon"};
    display_txt_title_credit(n_window, menu_pause_txt.txt_name, 200, 150);
    display_txt_basic(n_window, menu_pause_txt.txt_play, 300, 325);
    display_txt_basic(n_window, menu_pause_txt.txt_option, 300, 375);
    display_txt_basic(n_window, menu_pause_txt.txt_exit, 300, 425);
    sfTexture* texture_cdt = sfTexture_createFromFile("./res/credit.png", NULL);
    sfSprite* sprite_cdt = sfSprite_create();
    sfSprite_setTexture(sprite_cdt, texture_cdt, sfTrue);
    sfSprite_setPosition(sprite_cdt, (sfVector2f){1200, 300});
    sfRenderWindow_drawSprite(n_window, sprite_cdt, NULL);
}

int printf_credit(int tmp)
{
    if (tmp == 1) {
        char *credit = "This game was made by Romain Collignon in tek1. It was \
made between 24/11/2022 and 30/11/2022. Your copyrights are reserved to \
the other, creator and developer of this game.\nIt is forbidden to modify \
any part of the code whether it is the resources, include, source or \
others.\nGood game on the best of my_hunter !\n";
        mini_printf("\n\nCredit :\n");
        mini_printf("%s", credit);
    } else {
        char *h = "To play the game \"THE HUNTHER\" you must click on the \
crows to increase the score and get your best score. To quit the game from \
anywhere you can use the escape key.To win a game you need better than your \
\"best score\" and to lose it's by spanking less than your \"best score\"\n\n";
        char *h2 = "/!\\During the game, all \actions (except click on the \
crow) must be repeated several times before being carried out (to avoid \
\"missclicks\"). /!\\";
        mini_printf("\n\nInformation :\n");
        mini_printf("%s\n%s\n\n\n", h, h2);
    }
    return 0;
}

int main_credit(sfRenderWindow* window, scr *score)
{
    printf_credit(1);
    sfTexture* tture = sfTexture_createFromFile("./res/font_credit.jpg", NULL);
    sfSprite* sprite;
    sfEvent event;
    int tmp = 3;
    if (!window)
        return EXIT_FAILURE;
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, tture, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        tmp = cherch_perif_credit(window, event);
        if (tmp == 42 || tmp == 1 || tmp == 0)
            return tmp;
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        display_all_credit(window);
        sfRenderWindow_display(window);
    }
    return my_destroy(sprite, tture);
}
