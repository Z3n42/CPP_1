NAME= this_is_brain
CC = clang++
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
SRC = main.cpp

OBJ = $(SRC:%.cpp=%.opp)

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.opp:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all
