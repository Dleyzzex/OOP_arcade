##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Arcade
##

all		:
		# make -C ./lib/Ncurses
		make -C ./lib/SFML
		make -C ./lib/SDL
		make -C ./games/AZE
		make -C ./core

core	:
		make -C ./core

games	:
		make -C ./games/Snake

graphicals	:
		# make -C ./lib/Ncurses
		make -C ./lib/SFML
		make -C ./lib/SDL

fclean	:
		make fclean -C ./core/
		# make fclean -C ./lib/Ncurses
		make fclean -C ./lib/SFML
		make fclean -C ./lib/SDL
		make fclean -C ./games/AZE

re	:	fclean all

.PHONY	: 	all clean fclean re core games
