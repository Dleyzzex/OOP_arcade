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
		make -C ./games/AZE
		# Core
		make -C ./core

core	:
		make -C ./core

games	:
		make -C ./games/Snake

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
		make fclean -C ./games/AZE
		# Core
		make fclean -C ./core/

re	:	fclean all

.PHONY	: 	all clean fclean re core games
