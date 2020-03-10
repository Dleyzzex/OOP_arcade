##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Arcade
##

all		:
		make -C ./core
		make -C ./lib/Ncurses
		make -C ./lib/SFML
		mv ./core/arcade ./

core	:
		make -C ./core
		mv ./core/arcade ./

games	:
		make -C ./games/Snake

graphicals	:
		make -C ./lib/Ncurses
		make -C ./lib/SFML

fclean	:
		make fclean -C ./nm
		make fclean -C ./objdump

re	:	fclean all

.PHONY	: 	all clean fclean re core games
