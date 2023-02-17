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
#include <sys/stat.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include "struct_menu.h"
#include "my.h"

void display_all_menu(sfRenderWindow* n_window)
{
    int score = file_score(0);
    char *char_score = my_put_nbr_modif(score);
    char_score = my_revstr(char_score);
    txt menu_txt = {"THE HUNTER", "Settings", "Play", "credit", "exit", \
        "by Romain. COllignon"};
    display_txt_score_2(n_window, "Best score :", 1620, 10);
    display_txt_score_2(n_window, char_score, 1850, 10);
    display_txt_title(n_window, menu_txt.txt_name, 200, 150);
    display_txt_basic(n_window, menu_txt.txt_play, 300, 325);
    display_txt_basic(n_window, menu_txt.txt_option, 300, 375);
    display_txt_basic(n_window, menu_txt.txt_exit, 300, 425);
}

void display_all_game(sfRenderWindow* n_window, ps position, i_txt *info_txt,
ds *display)
{
    txt menu_txt;

    menu_txt.txt_bst_score = "Your score :";
    char *char_score = my_put_nbr_modif(position.score);
    if (position.score >= 10)
        char_score = my_revstr(char_score);
    int score_B = file_score(0);
    char *char_score_B = my_put_nbr_modif(score_B);
    display->font_01 = menu_txt.txt_bst_score;
    display->font_02 = char_score;
    display_txt_score_2(n_window, "Best score :", 1620, 10);
    display_txt_score_2(n_window, my_revstr(char_score_B), 1850, 10);
    display_txt_score(n_window, menu_txt.txt_bst_score, info_txt);
    display_txt_score_int(n_window, char_score, info_txt);
    display_game_01(n_window, "Back menu", info_txt);
    display_game_02(n_window, "Exit", info_txt);
}

int printf_error(void)
{
    mini_printf("Error or Argument : There is too much or\
not enough argument! Or missing file!\n");
    return 84;
}

char *name(void)
{
    char *name = "THE HUNTER";
    return name;
}
