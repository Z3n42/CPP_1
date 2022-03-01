NAME = Polymorphism

SRC =	main.cpp\
		Animal.cpp\
		Dog.cpp\
		Cat.cpp\
		WrongAnimal.cpp\
		WrongDog.cpp\
		WrongCat.cpp\

OBJ = $(SRC:.cpp=.o)

INCLUDE = Animal.hpp\
		Dog.hpp\
		Cat.hpp\
		WrongAnimal.hpp\
		WrongDog.hpp\
		WrongCat.hpp\

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


