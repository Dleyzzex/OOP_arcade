##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Snake
##

DIR_SRC	=	./src/
DIR_INC	=	./include/
DIR_INT = 	./lib/SFML/include

NAME	=	lib_arcade_snake.so

SRC		=	$(DIR_SRC)main.cpp \

OBJS	=	$(SRC:.cpp=.o)

CXXFLAGS	+=	-Wall -Wextra -I$(DIR_INC) -I$(DIR_INT) -g

all	:	$(OBJS)
		gcc -shared -o $(NAME) $(OBJS)
		mv $(NAME) ../

clean	:
		@rm -f $(OBJS)

fclean	:	clean
		@rm -f ../$(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re