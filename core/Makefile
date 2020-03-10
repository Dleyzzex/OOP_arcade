##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Core
##

DIR_INC =	./include/
INC_ALL	=	-I $(DIR_INC)interface/ \
			-I $(DIR_INC)tools/ \
			-I $(DIR_INC)components/ \
			-I $(DIR_INC)errors/ \
			-I $(DIR_INC) \

DIR_SRC	=	./src/

NAME	=	arcade

SRC		=	$(DIR_SRC)main.cpp \

OBJS	=	$(SRC:.cpp=.o)

CXXFLAGS	+= -Wall -Wextra -W $(INC_ALL)

all		:	$(OBJS)
			g++ -o $(NAME) $(OBJS)

debug	:	$(OBJS)
			g++ -g -o $(NAME) $(OBJS)

clean	:
		@rm -f $(OBJS)

fclean	:	clean
		@rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re