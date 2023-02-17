/*
** EPITECH PROJECT, 2022
** struct_menu.h
** File description:
** struct for all game
*/

#ifndef STRUCT_MENU_H
    #define STRUCT_MENU_H
    typedef struct menu_txt {
        char* txt_name;
        char* txt_settings;
        char* txt_play;
        char* txt_option;
        char* txt_exit;
        char* txt_by;
        char* txt_bst_score;
    } txt;

    typedef struct score {
        int best_score;
        int tmp_score;
    } scr;

    typedef struct position {
        int pos_x_01;
        int pos_y_01;
        int rect_01;
        int score;
        int tmp_m;
        int tmp_b;
    } ps;

    typedef struct info_txt {
        int tmp_01;
        int tmp_score_01;
        int x_01;
        int y_01;
        sfFont* font_01;
        sfText* txt_01;
        int x_02;
        int y_02;
        sfFont* font_02;
        sfText* txt_02;
        int x_03;
        int y_03;
        int x_04;
        int y_04;
    } i_txt;

    typedef struct menu_pause_txt {
        char* txt_name;
        char* txt_settings;
        char* txt_play;
        char* txt_option;
        char* txt_exit;
        char* txt_by;
        char* txt_bst_score;
    } p_txt;

    typedef struct display {
        sfTexture* fond_game;
        sfFont* font_01_s_t;
        sfText* text_01_s_t;
        char *font_01;
        sfFont* font_02_s_t;
        sfText* text_02_s_t;
        char *font_02;
        sfFont* font_03_s_b;
        sfText* text_03_s_b;
        char *font_03;
        sfFont* font_04_s_b;
        sfText* text_04_s_b;
        char *font_04;
    } ds;
#endif /* !STRUCT_MENU_H */
