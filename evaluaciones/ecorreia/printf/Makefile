# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 18:58:08 by ecorreia          #+#    #+#              #
#    Updated: 2021/10/11 18:06:00 by ecorreia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =ft_printf.c	\
	ft_char.c		\
	ft_hexadecimal.c\
	ft_integer.c		\
	ft_pointer.c	\
	ft_string.c		\
	ft_unsigned.c	\

NAME = libftprintf.a

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

CC = clang

CC_FLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)%.o : %.c ft_printf.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@clang $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	@ar r $(NAME) $(OBJECTS_PREFIXED)
	@echo "Damelo papa!"

all: $(NAME)

clean:
	rm -rf $(OBJS_DIR)


