##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC =	src/function/mini_printf.c \
		src/function/my_put_nbr.c \
		src/function/my_putchar.c \
		src/function/my_putstr.c \
		src/function/my_compute_power_rec.c \
		src/function/my_revstr.c \
		src/function/my_getnbr.c \
		src/function/int_pass_char.c \
		src/display_txt.c \
		src/display_menu.c \
		src/display_game.c \
		src/periph.c \
		src/function.c \
		src/function_score.c \
		src/main_pause.c \
		src/main_credit.c \
		src/verif_file.c \
		src/main.c

OBJ =	$(SRC:.c=.o)

CFLAGS = -I ./include/

CSFMLFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

NAME =	my_hunter

all:	$(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) $(CFLAGS) $(CSFMLFLAGS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean:
	rm -f $(OBJ)

re:	fclean all

auteur:
	echo $(USER) > auteur
