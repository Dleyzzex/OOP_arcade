##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Ncurses
##

DIR_SRC	=	./src/
DIR_INC	=	../../include/interface
# DIR_INC	=	./lib/Ncurses/include

NAME	=	lib_arcade_Ncurses.so

SRC		=   $(DIR_SRC)Ncurses.cpp \

OBJS	=	$(SRC:.cpp=.o)

CXXFLAGS	+=	-Wall -Wextra -I $(DIR_INC) -I ./include -g -fPIC

all	:	$(OBJS)
		g++ -shared -o $(NAME) $(OBJS) -lncurses
		mv $(NAME) ../

clean	:
		@rm -f $(OBJS)

fclean	:	clean
		@rm -f ../$(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
