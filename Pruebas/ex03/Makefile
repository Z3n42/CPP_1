# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 20:12:25 by ingonzal          #+#    #+#              #
#    Updated: 2023/03/05 19:59:44 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = FFVII

NAME_S = FFVII_Sanitized

NAME_L = FFVII_Leaks

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

AR = ar rcs

RM = rm -f

S = -fsanitize=address -g3

FILES = AMateria \
	Cure \
	Character \
	Ice \
	MateriaSource \
	main \

FILES_B = AMateria \
	  Cure \
	  Character \
	  Ice \
  	  MateriaSource \
	  main_leaks \

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
