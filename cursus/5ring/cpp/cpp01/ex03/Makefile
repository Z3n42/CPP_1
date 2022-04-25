# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 20:12:25 by ingonzal          #+#    #+#              #
#    Updated: 2022/04/25 14:18:45 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = Living_Dead

CC = clang++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

AR = ar rcs

RM = rm -f

#S = -fsanitize=address -g3

FILES = main \
		Weapon \
		HumanA \
		HumanB \

SRCS_DIR = ./
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.cpp.o: $(SRCS)
	@$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJS)
		@$(CC) $(FLAGS) $(S) $^ -o $@ 
		@echo "He bites me"

all: $(NAME)

clean:
		@$(RM) $(OBJS)
		@echo "Zombies eat brainzz"

fclean: clean
		@$(RM) $(NAME)
		@echo "u arr zzafe"

re: clean all

.PHONY: clean fclean %.o
