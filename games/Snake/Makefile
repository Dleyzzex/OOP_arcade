##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Ncurses
##

DIR_SRC	=	./src/
DIR_INC	=	./include
DIR_INT	=	../../include/interface/

NAME	=	lib_arcade_nibbler.so

SRC		=   $(DIR_SRC)Snake.cpp \

OBJS	=	$(SRC:.cpp=.o)

CXXFLAGS	+=	-Wall -Wextra -I$(DIR_INC) -I$(DIR_INT) -g -fPIC

all	:	$(OBJS)
		g++ -shared -o $(NAME) $(OBJS) -lncurses
		mv $(NAME) ../

clean	:
		@rm -f $(OBJS)

fclean	:	clean
		@rm -f ../$(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
