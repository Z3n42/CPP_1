# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/29 10:44:46 by ingonzal          #+#    #+#              #
#    Updated: 2021/05/29 12:29:56 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =
OBJS = $(SRC:.c=.o)
NAME = libft.a
RM = rm -f
CC = ar
CFLAGS = -c -r -s

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)  

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: clean fclean %.o
