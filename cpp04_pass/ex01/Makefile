# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 20:12:25 by ingonzal          #+#    #+#              #
#    Updated: 2023/02/26 16:47:35 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = Animals_01

NAME_S = Animals_01_Sanitized

NAME_L = Animals_01_Leaks

CC = c++

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
	Brain \

FILES_B = main_leaks \
	  Animal \
	  WrongAnimal \
	  Dog \
	  Cat \
	  WrongCat \
	  Brain \

SRCS_DIR = ./
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

SRCS_DIR = ./
SRCS_B = $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(FILES_B)))

OBJS_DIR = ./
OBJS_B = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_B)))

.cpp.o: $(SRCS)
	@$(CC) $(FLAGS) -c -o $@ $<

.cpp.o_B: $(SRCS_B)
	@$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJS)
		@$(CC) $(FLAGS) $^ -o $@ 
		@echo "The animals have been released"

san : $(NAME_S)

$(NAME_S): $(OBJS)
		@$(CC) $(FLAGS) $(S) $^ -o $@ 
		@echo "The animals have been sanitized"

leaks : $(NAME_L)

$(NAME_L): $(OBJS_B)
		@$(CC) $(FLAGS) $^ -o $@ 
		@echo "The animals have been their leaks watched"

all: $(NAME)

clean:
		@$(RM) $(OBJS)
		@$(RM) $(OBJS_B)
		@echo "Cleaning the animals"

fclean: clean
		@$(RM) $(NAME)
		@$(RM) $(NAME_S)
		@$(RM) $(NAME_L)
		@echo "Putting on the leash and muzzle"

re: clean all

.PHONY: clean fclean san  %.o
