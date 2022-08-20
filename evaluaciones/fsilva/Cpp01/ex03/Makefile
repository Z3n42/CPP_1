NAME = unnecessary_violence
CC = clang++
CFLAGS = -Werror -Wall -Wextra
RM = rm -rf
SRC =	main.cpp\
		Weapon.cpp\
		HumanA.cpp\
		HumanB.cpp

.PHONY: all clean re fclean

OBJ = $(SRC:%.cpp=%.opp)

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
