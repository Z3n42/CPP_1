# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 20:12:25 by ingonzal          #+#    #+#              #
#    Updated: 2022/06/21 17:47:01 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = FragTrap

CC = clang++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g -Wshadow -Wno-shadow

AR = ar rcs

RM = rm -f

S = -fsanitize=address -g3

FILES = main \
	ClapTrap \
	ScavTrap \
	FragTrap \

SRCS_DIR = ./
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.cpp.o: $(SRCS)
	@$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJS)
		@$(CC) $(FLAGS) $(S) $^ -o $@ 
		@echo "It's a Trap"

all: $(NAME)

clean:
		@$(RM) $(OBJS)
		@echo "Cleaning up human remains"

fclean: clean
		@$(RM) $(NAME)
		@echo "Collecting spare parts"

re: clean all

.PHONY: clean fclean %.o
