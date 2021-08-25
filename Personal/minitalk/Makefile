# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 20:12:25 by ingonzal          #+#    #+#              #
#    Updated: 2021/08/24 20:52:24 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# MAKEFLAGS += -s

SERVER = server
CLIENT = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

SANITIZE = -fsanitize=address -g3

LIBFT = -Llibft -lft

FILES = server \
		client \
 
SRCS_DIR = ./
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

all: pre $(SERVER) $(CLIENT)

$(SERVER): $(OBJS)
		$(CC) $(FLAGS) $^ $(LIBFT) -o $@ 

$(CLIENT): $(OBJS)
		$(CC) $(FLAGS) $^ $(LIBFT) -o $@ 
pre:
	$(MAKE) -C ./libft

clean:
		$(MAKE) clean -C ./libft
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(SERVER)
		$(RM) $(CLIENT)
		$(MAKE) fclean -C ./libft

re: clean all

.PHONY: clean fclean %.o
