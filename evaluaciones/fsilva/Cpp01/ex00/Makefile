NAME = brainzz
CC = clang++
CFLAGS = -Wall -Werror -Wextra -std=c++98#-fsanitize=address
SRC =	main.cpp\
		Zombie.cpp\
		newZombie.cpp\
		randomChump.cpp

OBJ = $(SRC:%.cpp=%.opp)
RM = rm -rf

.PHONY: all clean fclean re

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
	$(MAKE)
