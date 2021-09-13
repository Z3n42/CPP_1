# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 15:05:23 by dmarquez          #+#    #+#              #
#    Updated: 2021/09/07 17:18:12 by dmarquez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = so_long.c error_msg.c map_info.c draw_map.c check_map.c close.c move.c
SRCGNL = gnl/get_next_line_utils.c gnl/get_next_line.c
OBJS = $(SRC:.c=.o)
BONUSSRC =
BONUSOBJS = $(SRC:.c=.o)
INCLUDE = ./libft ./mlx

CC = gcc
CFLAGS = -Wall -Werror -Wextra

RM = rm -f
LIBX = -Lmlx -lmlx -framework OpenGL -framework AppKit
SAN = -fsanitize=address -g3

%.o : %.c
	@$(CC) $(CFLAGS) -I. -c $< -o $@

$(NAME) : $(OBJS) $(INCLUDE)
	@make -C ./libft
	@make -C ./mlx
	@cp libft/libft.a .
	@$(CC) $(CFLAGS) $(SAN) libft.a $(SRCGNL) $(LIBX) $(OBJS) -o $(NAME)
	@echo "\033[92mMandatory so_long assembled Master\033[0m"

#<<<<<<<<Utils>>>>>>>>>
all : $(NAME)

clean :
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "\033[34mTemporary files cleaned\033[0m"
	@make clean -C ./libft
	@make clean -C ./mlx

fclean : clean
	@$(RM) $(NAME) a.out
	@make fclean -C ./libft
	@$(RM) libft.a
	@echo "\033[35mAll clean Master\033[0m"

re : msgre fclean msg all


#<<<<<<<<Lets Talk>>>>>>>>>
msg :
	@echo Compiling...

msgre :
	@echo Your wish is my command Master

.PHONY: all clean fclean re bonus msg msgre
