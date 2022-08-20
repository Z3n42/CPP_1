NAME = more_brainzzzz
CC = clang++
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address 
SRC =	main.cpp\
		Zombie.cpp\
		ZombieHorde.cpp

OBJ = $(SRC:%.cpp=%.opp)
RM = rm -rf

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
