# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 20:12:25 by ingonzal          #+#    #+#              #
#    Updated: 2022/06/05 19:28:25 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = KarenFilter

CC = clang++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

AR = ar rcs

RM = rm -f

# S = -fsanitize=address -g3

FILES = main \
	karen \

SRCS_DIR = ./
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

.cpp.o: $(SRCS)
	@$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(OBJS)
		@$(CC) $(FLAGS) $(S) $^ -o $@ 
		@echo "The customer is always right"

all: $(NAME)

clean:
		@$(RM) $(OBJS)
		@echo "Give me the claim sheet please"

fclean: clean
		@$(RM) $(NAME)
		@echo "I will never return to this place"

re: clean all

.PHONY: clean fclean %.o
