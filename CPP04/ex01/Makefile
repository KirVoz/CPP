SRC = main.cpp \
	  Animal.cpp \
	  Dog.cpp \
	  Cat.cpp \
	  Brain.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++

RM = rm -f

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -fsanitize=address

NAME = deep_copy

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
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

.PHONY: all clean fclean re vg
