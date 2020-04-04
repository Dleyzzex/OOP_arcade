##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## SFML
##

DIR_SRC	=	./src/
DIR_INC	=	../../include/interface/
DIR_INT = 	./include/

NAME	=	lib_arcade_SDL.so

SRC	=	$(DIR_SRC)Sdl.cpp \

OBJS	=	$(SRC:.cpp=.o)

CXXFLAGS	+=	-Wall -Wextra -I$(DIR_INC) -I$(DIR_INT) -g -fPIC

all	:	$(OBJS)
		g++ -shared -o $(NAME) $(OBJS) -lSDL2 -lSDL2_ttf
		mv $(NAME) ../

clean	:
		@rm -f $(OBJS)

fclean	:	clean
		@rm -f ../$(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
