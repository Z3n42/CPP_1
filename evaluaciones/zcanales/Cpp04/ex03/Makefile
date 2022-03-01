NAME = Inter_Abs

SRC =	main.cpp\
		AMateria.cpp\
		Ice.cpp\
		Cure.cpp\
		Character.cpp\
		MateriaSource.cpp\

OBJ = $(SRC:.cpp=.o)

INCLUDE = AMateria.hpp\
	Ice.hpp\
	Cure.hpp\
	ICharacter.hpp\
	IMateriaSource.hpp\
	Character.hpp\
	MateriaSource.hpp\

CC = clang++

FLAG =  -Wall -Wextra -Werror #-g3 -fsanitize=address

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


