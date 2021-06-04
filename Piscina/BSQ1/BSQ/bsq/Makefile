# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iaburto- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 10:37:28 by iaburto-          #+#    #+#              #
#    Updated: 2021/05/06 19:12:07 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = ./bsq.c ./ft_archarge.c ./ft_ardata.c ./ft_check.c ./ft_tbl_error.c
OBJS = $(SRC:.c=.o)
NAME = BSQ
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
