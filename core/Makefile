##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Core
##

DIR_INC =	./include/
INC_ALL	=	-I .$(DIR_INC)interface/ \
			-I $(DIR_INC)tools/ \
			-I $(DIR_INC)components/ \
			-I $(DIR_INC)errors/ \
			-I $(DIR_INC) \

DIR_SRC	=	./src/

NAME	=	arcade

SRC		=	$(DIR_SRC)main.cpp \
			$(DIR_SRC)error_gestion.cpp \
			$(DIR_SRC)parser.cpp \
			$(DIR_SRC)core.cpp \

OBJS	=	$(SRC:.cpp=.o)

CXXFLAGS	+= -Wall -Wextra -W $(INC_ALL) -g

all		:	$(OBJS)
			g++ -o $(NAME) $(OBJS) -ldl
			mv $(NAME) ../

debug	:	$(OBJS)
			g++ -g -o $(NAME) $(OBJS)

clean	:
		@rm -f $(OBJS)

fclean	:	clean
		@rm -f ../$(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
