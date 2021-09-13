# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 15:05:23 by dmarquez          #+#    #+#              #
#    Updated: 2021/08/25 11:13:38 by dmarquez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c ft_format.c ft_put_c.c ft_put_s.c ft_put_d_i.c ft_utils.c ft_put_u.c ft_put_x.c ft_put_p.c
OBJS = $(SRC:.c=.o)

LIB = ar rcs
CC = gcc
CFLAGS = -Wall -Werror -Wextra

RM = rm -f

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS) $(INCLUDE)
	@$(LIB) $(NAME) $(OBJS)
	@echo "\033[92mMandatory Printf assembled Master\033[0m"

#<<<<<<<<Utils>>>>>>>>>
all : $(NAME)

clean :
	@$(RM) $(OBJS)
#	@echo "\033[34mprintf temporary files cleaned\033[0m"

fclean : clean
	@$(RM) $(NAME)

re : msgre fclean msg all

#<<<<<<<<Lets Talk>>>>>>>>>
msg :
	@echo Compiling...

msgre :
	@echo Your wish is my command Master

.PHONY: all clean fclean re bonus msg msgre
