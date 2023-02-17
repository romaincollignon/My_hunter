/*
** EPITECH PROJECT, 2022
** main_pause.c
** File description:
** main pause
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

int cherch_perif_pause(sfRenderWindow* w, sfEvent event)
{
    int *b1[] = {300, 520, 440, 480};
    int *b2[] = {300, 520, 340, 380};
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

void display_all_pause(sfRenderWindow* n_window, scr *score)
{
    p_txt menu_pause_txt = {"Partie Fini !", "Menu", "Replay", "Home", \
        "exit", "by Romain. COllignon"};
    int score_b = file_score(0);
    char *char_score = my_put_nbr_modif(score_b);
    char *tmp_score = my_put_nbr_modif(score->tmp_score);
    if (score->tmp_score < score_b)
        menu_pause_txt.txt_name = "Game Lost !";
    else
        menu_pause_txt.txt_name = "Game Won !";
    display_txt_score_2(n_window, "Best score :", 1620, 10);
    display_txt_score_2(n_window, "Your score :", 1620, 50);
    display_txt_score_2(n_window, my_revstr(char_score), 1850, 10);
    display_txt_score_2(n_window, my_revstr(tmp_score), 1850, 50);
    display_txt_title(n_window, menu_pause_txt.txt_name, 200, 150);
    display_txt_basic(n_window, menu_pause_txt.txt_play, 300, 325);
    display_txt_basic(n_window, menu_pause_txt.txt_option, 300, 375);
    display_txt_basic(n_window, menu_pause_txt.txt_exit, 300, 425);
}

int main_pause(sfRenderWindow* window, scr *score)
{
    sfTexture* texture = sfTexture_createFromFile("./res/fond_map.png", NULL);
    sfSprite* sprite;
    sfEvent event;
    int tmp = 3;
    if (!window)
        return EXIT_FAILURE;
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    int speed = 10;
    while (sfRenderWindow_isOpen(window)) {
        tmp = cherch_perif_pause(window, event);
        if (tmp == 42 || tmp == 1 || tmp == 0)
            return tmp;
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        display_all_pause(window, score);
        sfRenderWindow_display(window);
    }
    return my_destroy(sprite, texture);
}
