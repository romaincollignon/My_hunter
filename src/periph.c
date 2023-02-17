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

#include <../include/struct_menu.h>
#include <../include/my.h>

int mw1(int** zone, sfRenderWindow* window, sfEvent event)
{
    sfVector2i mouse = sfMouse_getPosition(window);
    if (mouse.x >= zone[0] && mouse.x <= zone[1]) {
        if (mouse.y >= zone[2] && mouse.y <= zone[3])
            return 1;
    }
    return 0;
}

int mw2(int** zone, sfRenderWindow* window)
{
    sfVector2i mouse = sfMouse_getPosition(window);
    if (mouse.x >= zone[0] && mouse.x <= zone[1]) {
        if (mouse.y >= zone[2] && mouse.y <= zone[3])
            return 1;
    }
    return 0;
}

int cherch_perif(sfRenderWindow* w, sfEvent event)
{
    int *b1[4] = {300, 520, 440, 480};
    int *b2[4] = {300, 520, 340, 380};
    int *b3[4] = {300, 520, 380, 440};
    sfEvent act;
    while (sfRenderWindow_pollEvent(w, &act)) {
        if (act.type == sfEvtClosed) {
            sfRenderWindow_close(w);
            return 0;
        } if (act.type == sfEvtKeyPressed && act.key.code == sfKeyEscape) {
            return 42;
        } if (mw1(b1, w, event) == 1 && act.type == sfEvtMouseButtonPressed) {
            return 42;
        } if (mw1(b2, w, event) == 1 && act.type == sfEvtMouseButtonPressed) {
            return 1;
        } if (mw1(b3, w, event) == 1 && act.type == sfEvtMouseButtonPressed) {
            return 3;
        }
    } return 4;
}

int cherch_perif_game(sfRenderWindow* w, sfEvent event)
{
    int *b1[4] = {1700, 1920, 980, 1080};
    int *b2[4] = {1840, 1920, 950, 980};
    sfEvent act;
    while (sfRenderWindow_pollEvent(w, &act)) {
        if (act.type == sfEvtClosed) {
            return 42;
        } if (act.type == sfEvtKeyPressed && act.key.code == sfKeyEscape) {
            return 42;
        } if (mw1(b1, w, event) == 1 && act.type == sfEvtMouseButtonPressed) {
            return 0;
        } if (mw1(b2, w, event) == 1 && act.type == sfEvtMouseButtonPressed) {
            return 42;
        }
    }
    return 1;
}

int main_mouse_bird(sfRenderWindow* w, ps *position)
{
    int *bird_01[4] = {position->pos_x_01, position->pos_x_01 + 100,\
    position->pos_y_01, position->pos_y_01 + 100};
    sfEvent act;
    while (sfRenderWindow_pollEvent(w, &act)) {
        if (mw2(bird_01, w) == 1 && act.type == sfEvtMouseButtonPressed) {
            sfRenderWindow_close(w);
            return 1;
        }
    }
    return 0;
}
