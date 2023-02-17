/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** all prototypes
*/

#ifndef MY_H_
    #define MY_H_
    #include <fcntl.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>

    sfVector2f get_position(int x, int y);
    void display_txt_title(sfRenderWindow* n_window, char *txt, int x, int y);
    void display_txt_basic(sfRenderWindow* n_window, char *txt, int x, int y);
    void display_txt_score(sfRenderWindow* n_window, char *txt, \
        i_txt *info_txt);
    void display_txt_score_int(sfRenderWindow* n_window, char *score_m, \
        i_txt *info_txt);
    void display_all_menu(sfRenderWindow* n_window);
    void display_all_pause(sfRenderWindow* n_window, scr *score);
    void display_all_game(sfRenderWindow* n_window, ps position, \
    i_txt *info_txt, ds *display);
    int cherch_perif(sfRenderWindow* n_window, sfEvent event);
    int my_random(int min, int max);
    int mini_printf(const char *format, ...);
    char *my_put_nbr_modif(int nb);
    int main_menu(sfRenderWindow* window, scr *score);
    int main_game(sfRenderWindow* window, scr *score);
    int main_pause(sfRenderWindow* window, scr *score);
    int main_credit(sfRenderWindow* window, scr *score);
    int main_bird(sfRenderWindow* window, scr *score, ps *position, \
        sfEvent event);
    int function_game(sfRenderWindow* window);
    int bird_sprite(sfRenderWindow* window, int tmp, ps *position);
    int main_mouse_bird(sfRenderWindow* n_window, ps *position);
    int my_destroy(sfSprite *sprite, sfTexture *texture);
    int bird(sfRenderWindow* window, ps *position, scr *score);
    int verif_pos_bird(sfRenderWindow* window, ps *position, sfEvent event);
    int	my_getnbr(char const *str);
    char* int_pass_char(int nbr);
    int my_lenint_x(int nbr);
    char *my_revstr(char *str);
    void display_game_01(sfRenderWindow* n_window, char *txt, i_txt *info_txt);
    void display_game_02(sfRenderWindow* n_window, char *txt, i_txt *info_txt);
    int printf_credit(int tmp);
    int printf_error(void);
    int my_strlen(char const *str);
    int file_score(int score);
    void display_txt_score_2(sfRenderWindow* n_window, char *txt, int x, int y);
    int mw1(int** zone, sfRenderWindow* window, sfEvent event);
    int mw2(int** zone, sfRenderWindow* window);
    int my_destroy_game(sfSprite *sprite, sfTexture *texture, i_txt *info_txt,\
    ds *display);
    int cherch_perif_game(sfRenderWindow* w, sfEvent event);
    int verif_file(void);
    char *name(void);
#endif /* !MY_H_ */
