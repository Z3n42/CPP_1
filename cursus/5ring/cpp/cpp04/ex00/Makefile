# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 20:12:25 by ingonzal          #+#    #+#              #
#    Updated: 2022/07/10 18:18:47 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = Animals_00

CC = clang++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

AR = ar rcs

RM = rm -f

S = -fsanitize=address -g3

FILES = main \
		Animal \
		WrongAnimal \
		Dog \
		Cat \
		WrongCat \

SRCS_DIR = ./
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.cpp.o: $(SRCS)
	@$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJS)
		@$(CC) $(FLAGS) $(S) $^ -o $@ 
		@echo "The animals have been released"

all: $(NAME)

clean:
		@$(RM) $(OBJS)
		@echo "Cleaning the animals"

fclean: clean
		@$(RM) $(NAME)
		@echo "Putting on the leash and muzzle"

re: clean all

.PHONY: clean fclean %.o
