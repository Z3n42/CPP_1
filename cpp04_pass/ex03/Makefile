# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 20:12:25 by ingonzal          #+#    #+#              #
#    Updated: 2023/03/21 21:08:05 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME   = FFVII
NAME_V = FFVII_Sanitized
NAME_L = FFVII_Leaks
NAME_T = FFVII_Test

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
SRCS_T = $(wildcard $(SRCS_MAIN)main_test.cpp) $(wildcard $(SRCS_DIR)*_v.cpp)

OBJS = $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.cpp=.o)))
OBJS_V = $(addprefix $(OBJS_DIR), $(notdir $(SRCS_V:.cpp=.o)))
OBJS_L = $(addprefix $(OBJS_DIR), $(notdir $(SRCS_L:.cpp=.o)))
OBJS_T = $(addprefix $(OBJS_DIR), $(notdir $(SRCS_T:.cpp=.o)))

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

$(NAME_V): $(OBJS_V)
		@$(CC) $(FLAGS) $(S) $^ -o $@ 
		@echo "Cloud: Swords never run from bullets."

leaks : $(NAME_L)

$(NAME_L): $(OBJS_L)
		@$(CC) $(FLAGS) $^ -o $@ 
		@echo "Cid: No, I guess if I had to choose, I'd put my money on the power of science."

ifrit : $(NAME_T)

$(NAME_T): $(OBJS_T)
		@$(CC) $(FLAGS) $^ -o $@ 
		@echo "Invocation: IFRIT"

all: $(NAME)

clean:
		@$(RM) $(OBJS_DIR)
		@echo "Sephiroth: the time......is now."

fclean: clean
		@$(RM) $(NAME)
		@$(RM) $(NAME_V)
		@$(RM) $(NAME_L)
		@$(RM) $(NAME_T)
		@echo "Sephiroth: What I have taught you is reality. What you remember is an illusion."

re: clean all

.PHONY: clean fclean san  %.o
