# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 20:12:25 by ingonzal          #+#    #+#              #
#    Updated: 2023/04/25 19:38:30 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME   = Bureaucracy
NAME_V = Bureaucracy_Sanitized

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

SRCS = $(wildcard $(SRCS_MAIN)main.cpp) $(wildcard $(SRCS_DIR)*.cpp)
SRCS_V = $(wildcard $(SRCS_MAIN)main_v.cpp) $(wildcard $(SRCS_DIR)*_v.cpp)

OBJS = $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.cpp=.o)))
OBJS_V = $(addprefix $(OBJS_DIR), $(notdir $(SRCS_V:.cpp=.o)))

$(NAME): $(OBJS)
		@$(CC) $(FLAGS) $^ -o $@ 
		@echo "Cloud: Muy bien, allévoy."

$(OBJS_DIR)%.o: $(SRCS_MAIN)%.cpp 
		@mkdir -p $(OBJS_DIR)
		@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp 
		@mkdir -p $(OBJS_DIR)
		@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

san : $(NAME_V)

$(NAME_V): $(OBJS)
		@$(CC) $(FLAGS) $(S) $^ -o $@ 
		@echo "Cloud: Swords never run from bullets."

all: $(NAME)

clean:
		@$(RM) $(OBJS_DIR)
		@echo "Sephiroth: the time......is now."

fclean: clean
		@$(RM) $(NAME)
		@$(RM) $(NAME_V)
		@echo "Sephiroth: What I have taught you is reality. What you remember is an illusion."

re: clean all

.PHONY: clean fclean san  %.o
