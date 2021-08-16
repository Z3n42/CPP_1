# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 20:12:25 by ingonzal          #+#    #+#              #
#    Updated: 2021/08/14 19:11:23 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES = ft_error \
		ft_chunk \
		ft_sort_chunk \
		ft_chunkup \
		ft_chunkdown \
		ft_mincheck \
		ft_maxcheck \
		ft_atoi_push \
		ft_swap_a \
		ft_swap_b \
		ft_swap_ss \
		ft_push_a \
		ft_push_b \
		ft_rotate_a \
		ft_rotate_b \
		ft_rotate_rr \
		ft_reverse_ra \
		ft_reverse_rb \
		ft_reverse_rr \
		ft_three \
		ft_five \
		ft_hundred \
		ft_fivehund \
		main \
		../libft_pass/ft_split \
		../libft_pass/ft_strtrim \
		../libft_pass/ft_substr \
		../libft_pass/ft_strlen \
		../libft_pass/ft_calloc \
		../libft_pass/ft_isalpha \
		ft_cheker \

SRCS_DIR = ./
SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

# .c.o: $(SRCS)
# 		$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
		$(CC) -o $@ $^

all: $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: clean all

.PHONY: clean fclean %.o
