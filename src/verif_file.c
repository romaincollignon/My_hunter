/*
** EPITECH PROJECT, 2022
** verif_file.c
** File description:
** verif file
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

int verif_file(void)
{
    char *tab[8] = {"./res/Bostana.ttf", "./res/cb_shet.png",
    "./res/CodeNext.ttf", "./res/credit.png", "./res/fond_game.png",
    "./res/fond_map.png", "./res/font_credit.jpg", "./res/Play_Pretend.otf"};
    for (int n = 0; n < 8; n++) {
        int addre_file = open(tab[n], O_RDONLY);
        if (addre_file == -1) {
            mini_printf("%i", n);
            close(addre_file);
            return 84;
        }
        close(addre_file);
    }
    return 0;
}
