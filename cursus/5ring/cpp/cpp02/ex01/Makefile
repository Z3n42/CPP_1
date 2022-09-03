# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 20:12:25 by ingonzal          #+#    #+#              #
#    Updated: 2022/09/03 20:37:31 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = FixedPoint

CC = clang++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

AR = ar rcs

RM = rm -f

S = -fsanitize=address -g3

FILES = main \
	Fixed \

SRCS_DIR = ./
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.cpp.o: $(SRCS)
	@$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJS)
		@$(CC) $(FLAGS) $^ -o $@ 
		@echo "Fixin points ...."

san: $(OBJS)
		@$(CC) $(FLAGS) $(S) $^ -o $(NAME) 
		@echo "Sanitizing points ...."

all: $(NAME)

clean:
		@$(RM) $(OBJS)
		@echo "Cleaning 1"

fclean: clean
		@$(RM) $(NAME)
		@echo "Cleaning 1.1"

re: clean all

.PHONY: clean fclean %.o
