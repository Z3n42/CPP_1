# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 20:12:25 by ingonzal          #+#    #+#              #
#    Updated: 2022/04/21 14:08:36 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = DreamJob

CC = clang++

FLAGS = -Wall -Wextra -Werror -g

AR = ar rcs

RM = rm -f

S = -fsanitize=address -g3

FILES = tests \
		Account \

SRCS_DIR = ./
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.cpp.o: $(SRCS)
	@$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJS)
		@$(CC) $(FLAGS) $(S) $^ -o $@ 
		@echo "Compilando"

all: $(NAME)

clean:
		@$(RM) $(OBJS)
		@echo "Limpiando"

fclean: clean
		@$(RM) $(NAME)
		@echo "a fondo"

re: clean all

.PHONY: clean fclean %.o
