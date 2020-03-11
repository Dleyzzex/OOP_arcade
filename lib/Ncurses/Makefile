##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Ncurses
##

DIR_SRC	=	./src/
DIR_INC	=	./include/
DIR_INC	=	./lib/Ncurses/include

NAME	=	lib_arcade_ncurses.so

SRC		=	$(DIR_SRC)main.cpp \

OBJS	=	$(SRC:.cpp=.o)

CXXFLAGS	+=	-Wall -Wextra -I$(DIR_INC) -I$(DIR_INT) -g

all	:	$(OBJS)
		gcc -shared -o $(NAME) $(OBJS) -lncurses
		mv $(NAME) ../

clean	:
		@rm -f $(OBJS)

fclean	:	clean
		@rm -f ../$(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
