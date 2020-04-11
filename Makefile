##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Arcade
##

all		:
		# Libs
		make -C ./lib/Ncurses
		make -C ./lib/SFML
		make -C ./lib/SDL
		# Games
		make -C ./games/Snake
		make -C ./games/Pacman
		# Core
		make -C ./core

core	:
		make -C ./core

games	:
#		make -C ./games/Snake
		make -C ./games/Pacman

graphicals	:
		make -C ./lib/Ncurses
		make -C ./lib/SFML
		make -C ./lib/SDL

fclean	:
		# Libs
		make fclean -C ./lib/Ncurses
		make fclean -C ./lib/SFML
		make fclean -C ./lib/SDL
		# Games
		make fclean -C ./games/Snake
		make fclean -C ./games/Pacman
		# Core
		make fclean -C ./core/

re	:	fclean all

.PHONY	: 	all clean fclean re core games
