# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 20:12:25 by ingonzal          #+#    #+#              #
#    Updated: 2023/03/19 21:40:58 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME   = FFVII
NAME_V = FFVII_Sanitized
NAME_L = FFVII_Leaks

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

AR = ar rcs
RM = rm -rf
S  = -fsanitize=address -g3

SRCS_MAIN = ./
SRCS_DIR  = src/
OBJS_DIR  = obj/
INCS_DIR  = inc/

HEADERS	 = ./$(INCS_DIR)
INCLUDES = $(addprefix -I, $(HEADERS))

SRCS = $(wildcard $(SRCS_MAIN)main.cpp) $(wildcard $(SRCS_DIR)*_m.cpp)
SRCS_V = $(wildcard $(SRCS_MAIN)main.cpp) $(wildcard $(SRCS_DIR)*_v.cpp)
SRCS_L = $(wildcard $(SRCS_MAIN)main_leaks.cpp) $(wildcard $(SRCS_DIR)*_v.cpp)

OBJS = $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.cpp=.o)))
OBJS_V = $(addprefix $(OBJS_DIR), $(notdir $(SRCS_V:.cpp=.o)))
OBJS_L = $(addprefix $(OBJS_DIR), $(notdir $(SRCS_L:.cpp=.o)))

$(NAME): $(OBJS)
		@$(CC) $(FLAGS) $^ -o $@ 
		@echo "The animals have been released"

$(OBJS_DIR)%.o: $(SRCS_MAIN)%.cpp 
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp 
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

san : $(NAME_V)

$(NAME_V): $(OBJS_V)
		@$(CC) $(FLAGS) $(S) $^ -o $@ 
		@echo "The animals have been sanitized"

leaks : $(NAME_L)

$(NAME_L): $(OBJS_L)
		@$(CC) $(FLAGS) $^ -o $@ 
		@echo "The animals have been their leaks watched"

all: $(NAME)

clean:
		@$(RM) $(OBJS_DIR)
		@echo "Cleaning the animals"

fclean: clean
		@$(RM) $(NAME)
		@$(RM) $(NAME_V)
		@$(RM) $(NAME_L)
		@echo "Putting on the leash and muzzle"

re: clean all

.PHONY: clean fclean san  %.o
