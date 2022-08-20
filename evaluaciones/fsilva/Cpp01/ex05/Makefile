NAME = unkaren
CC = clang++
CFLAGS = -Werror -Wall -Wextra #-fsanitize=address
RM = rm -rf

SRC =	main.cpp\
		Karen.cpp
OBJ = $(SRC:%.cpp=%.opp)

.PHONY: all re clean fclean

all: $(NAME)

%.opp:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all
