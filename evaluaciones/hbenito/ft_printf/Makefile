# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbenito- <hbenito-@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 18:47:31 by hbenito-          #+#    #+#              #
#    Updated: 2021/11/19 11:12:36 by hbenito-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE	= ft_printf.c \
		  ft_printword.c \
		  ft_printnumb.c

NAME	= libftprintf.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror 

AR		= ar -rcs

RM		= rm -f

INCLUDE	= ft_printf.h

OBJECTS	= $(SOURCE:.c=.o)

%.o: %.c
	$(CC) $(CLAGS) -c -o $@ $< 

$(NAME):	$(OBJECTS) $(INCLUDE)
		$(AR) $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
