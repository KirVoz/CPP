SRS = main.cpp \
	  Zombie.cpp \
	  zombieHorde.cpp

OBJ = $(SRS:.cpp=.o)

CC = c++

RM = rm -f

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

NAME = zombieHorde

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

vg: fclean $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -g -o $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) 10 bob

.PHONY: all clean fclean re
