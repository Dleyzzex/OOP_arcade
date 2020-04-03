NAME	= program

CC	= g++

RM	= rm -f

SRCS	= ./Ncurses.cpp

OBJS	= $(SRCS:.cpp=.o)


SRC	= ./Pacman.cpp

OBJ	= $(SRC:.cpp=.o)

CPPFLAGS = -I
CPPFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -lncurses


pacman: $(OBJ)
	 $(CC) $(OBJ) -o pacman $(LDFLAGS) -lncurses

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) pacman

re: fclean all

.PHONY: all clean fclean re
