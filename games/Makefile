##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Snake
##

DIR_SRC	=	./src/
DIR_INC	=	./include/
DIR_INT = 	./lib/SFML/include

NAME	=	lib_arcade_nibbler.so
NAMES	=	lib_arcade_pacman.so

SRC		=	$(DIR_SRC)Ncurses.cpp
OBJS	=	$(SRC:.cpp=.o)

SRCS	=	$(DIR_SRC)Pacman.cpp
OBJSS	=	$(SRCS:.cpp=.o)

CXXFLAGS	+=	-Wall -Wextra -I$(DIR_INC) -I$(DIR_INT) -g -fPIC

all	:	$(OBJS)
		gcc -shared -o $(NAME) $(OBJS) -lncurses $(CXXFLAGS)
		#mv $(NAME) ../
		g++ -shared -o $(NAMES) $(DIR_SRC)Pacman.cpp $(CXXFLAGS) -lncurses
		#mv $(NAMES) ../

clean	:
		@rm -f $(OBJS)

fclean	:	clean
		@rm -f ../$(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re