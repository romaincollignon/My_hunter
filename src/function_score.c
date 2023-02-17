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

char *open_score(void)
{
    char *chemin = "./tmp_score";
    struct stat st;
    stat(chemin, &st);
    char *file = malloc(sizeof(char) * (st.st_size + 1));
    int addre_file = open(chemin, O_RDONLY);
    if (addre_file == -1)
        return "84";
    read(addre_file, file, st.st_size);
    file[st.st_size] = '\0';
    close(addre_file);
    return file;
}

int file_score(int score)
{
    char *chemin = "./tmp_score";
    int file_score = open(chemin, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR |
S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    char *file = open_score();
    int best_score = my_getnbr(file);
    char *char_score = my_put_nbr_modif(score);
    if (my_strlen(file) == 0) {
        write(file_score, "0", 1);
        return 0;
    } if (best_score >= score) {
        close(file_score);
        return best_score;
    } else {
        write(file_score, my_revstr(char_score), my_strlen(char_score));
        close(file_score);
        return score;
    }
    return 0;
}

void display_txt_score_2(sfRenderWindow* n_window, char *txt, int x, int y)
{
    sfText* text;
    sfFont* font;
    font = sfFont_createFromFile("./res/Play_Pretend.otf");
    text = sfText_create();
    sfText_setString(text, txt);
    sfText_setPosition(text, get_position(x, y));
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfRenderWindow_drawText(n_window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}
