##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## AZE
##

DIR_SRC	=	./src/
DIR_INC	=	./include/

NAME	=	lib_arcade_game.so

SRC		=	$(DIR_SRC)game.cpp

OBJS	=	$(SRC:.cpp=.o)

CXXFLAGS	+=	-Wall -Wextra -I$(DIR_INC) -I$(DIR_INT) -g -fPIC

all	:	$(OBJS)
		gcc -shared -o $(NAME) $(OBJS) $(CXXFL0AGS)
		mv $(NAME) ../
clean	:
		@rm -f $(OBJS)

fclean	:	clean
		@rm -f ../$(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
