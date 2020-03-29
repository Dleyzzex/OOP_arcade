##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## SFML
##

DIR_SRC	=	./src/
DIR_INC	=	../../include/interface/
DIR_INT = 	./include/

NAME	=	lib_arcade_SFML.so

SRC	=	$(DIR_SRC)Sfml.cpp \

OBJS	=	$(SRC:.cpp=.o)

CXXFLAGS	+=	-Wall -Wextra -I$(DIR_INC) -I$(DIR_INT) -g -fPIC

all	:	$(OBJS)
		gcc -shared -o $(NAME) $(OBJS) -lsfml-graphics -lsfml-window -lsfml-system -lncurses
		mv $(NAME) ../

clean	:
		@rm -f $(OBJS)

fclean	:	clean
		@rm -f ../$(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
