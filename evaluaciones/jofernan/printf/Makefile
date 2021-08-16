NAME = libftprintf.a
CC = clang
CFLAGS = -Wall -Wextra -Werror
LIB = ar rcs
RM = rm -rf

FILES = extra/ft_pitoa \
		extra/ft_putstr_int \
		extra/write_nbr \
		extra/ft_putchar_int \
		extra/ft_hex_itoa \
		extra/write_hex_caps \
		extra/write_char \
		extra/write_pointer \
		extra/ft_strupper \
		extra/ft_putnbr_base_int \
		extra/ft_putnbr_uint \
		extra/write_hex \
		extra/write_string \
		extra/ft_putnbr_int \
		extra/write_int \
		srcs/ft_printf


SRC = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

.c.o: $(FILES)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS) $(NAME)
	$(MAKE) -C libft/
	mv libft/libft.a .
	ar rcs libft.a $(OBJS)
	mv libft.a $(NAME)

clean:
	$(MAKE) -C libft clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)
	$(RM) libft.a
	

all: $(NAME)

re: fclean all

.PHONY: all clean fclean libft re
