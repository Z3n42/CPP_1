NAME = Polymorphism_Brain

SRC =	main.cpp\
		Animal.cpp\
		Dog.cpp\
		Cat.cpp\
		Brain.cpp\

OBJ = $(SRC:.cpp=.o)

INCLUDE = Animal.hpp\
		Dog.hpp\
		Cat.hpp\
		Brain.cpp\

CC = clang++

FLAG =  -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ) $(INCLUDE) $(SRC)
	$(CC) $(FLAG) $(OBJ) -I. -o $(NAME)

%.o : %.cpp
		$(CC) $(FLAG) -c $< -o $@

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)
	rm -rf $(NAME).dSYM

re : fclean all

.PHONY: all clean fclean re


