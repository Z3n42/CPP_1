# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/02 16:38:27 by ingonzal          #+#    #+#              #
#    Updated: 2021/05/06 17:49:02 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./rush02.c ./utilities.c ./check_input.c
OBJS = $(SRC:.c=.o)
NAME = rush-02
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)  

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

.PHONY: all clean fclean %.o
