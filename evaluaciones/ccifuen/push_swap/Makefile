MAKEFLAGS += -s

NAME = push_swap

SRCS = main.c srcs/ft_push_swap.c srcs/ft_rotate.c srcs/ft_rev_rotate.c \
		srcs/ft_sort_50.c srcs/ft_track_5.c srcs/ft_get_info.c\
		srcs/ft_sort_100.c srcs/ft_track_11.c srcs/ft_sort_500.c \
		srcs/ft_sort_3.c srcs/ft_extras.c \

LIBFT = -Llibft -lft

OBJS = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

SANITIZE = -fsanitize=address -g3

$(NAME): $(OBJS)
		@echo Compilando cosas.... \¡\¡Espera!!.
		@$(MAKE) -C ./libft
		@$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)
		@echo Cosas compiladas. \¡Disfruta!.

all: $(NAME)

r: re
	@clear
	@./push_swap

clean:
		@$(MAKE) clean -C ./libft
		@rm -rf $(OBJS)
		@echo Cosas .o borradas.

fclean: clean
		@rm -rf $(NAME)
		@echo Cosa ejecutable también borrada.

re: fclean all