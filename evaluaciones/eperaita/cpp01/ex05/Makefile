NAME = karen

SRC =	main.cpp\
		Karen.cpp\

OBJ = $(SRC:.cpp=.o)

CC = clang++

INC = 	Karen.hpp\

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "\033[0;35m \033[1mReady!"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re: fclean all

.PHONY : re all fclean clean
