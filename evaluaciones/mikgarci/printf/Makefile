NAME = 	libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

FILES = Libft/ft_memset        \
        Libft/ft_bzero        \
        Libft/ft_memcpy       \
        Libft/ft_memccpy      \
        Libft/ft_memmove		\
        Libft/ft_memchr        \
        Libft/ft_memcmp        \
        Libft/ft_strlen        \
        Libft/ft_isalpha    	\
        Libft/ft_isdigit        \
        Libft/ft_isalnum        \
        Libft/ft_isascii        \
        Libft/ft_isprint        \
        Libft/ft_toupper        \
        Libft/ft_tolower        \
        Libft/ft_strchr       \
        Libft/ft_strrchr        \
        Libft/ft_strncmp       \
        Libft/ft_strlcpy        \
        Libft/ft_strlcat        \
        Libft/ft_strnstr       \
        Libft/ft_atoi       \
        Libft/ft_calloc        \
        Libft/ft_strdup      \
		Libft/ft_strtrim	\
		Libft/ft_substr		\
		Libft/ft_putchar_fd	\
		Libft/ft_putstr_fd		\
		Libft/ft_putendl_fd		\
		Libft/ft_putnbr_fd		\
		Libft/ft_putnbr		\
		Libft/ft_strjoin		\
		Libft/ft_itoa	\
		Libft/ft_split		\
		Libft/ft_strmapi	\
	  printf/ft_printf\
	  printf/ft_printhex\
	  printf/ft_printnum\
	  printf/ft_printstr\
	  printf/ft_contfun\
	  printf/ft_printfsrc\
	  printf/ft_printnumesrc\
	  printf/ft_printhexautils\
	  printf/ft_printwrite\

FILES_B = Libft/ft_memset        \
        Libft/ft_bzero        \
        Libft/ft_memcpy       \
        Libft/ft_memccpy      \
        Libft/ft_memmove		\
        Libft/ft_memchr        \
        Libft/ft_memcmp        \
        Libft/ft_strlen        \
        Libft/ft_isalpha    	\
        Libft/ft_isdigit        \
        Libft/ft_isalnum        \
        Libft/ft_isascii        \
        Libft/ft_isprint        \
        Libft/ft_toupper        \
        Libft/ft_tolower        \
        Libft/ft_strchr       \
        Libft/ft_strrchr        \
        Libft/ft_strncmp       \
        Libft/ft_strlcpy        \
        Libft/ft_strlcat        \
        Libft/ft_strnstr       \
        Libft/ft_atoi       \
        Libft/ft_calloc        \
        Libft/ft_strdup      \
		Libft/ft_strtrim	\
		Libft/ft_substr		\
		Libft/ft_putchar_fd	\
		Libft/ft_putstr_fd		\
		Libft/ft_putendl_fd		\
		Libft/ft_putnbr_fd		\
		Libft/ft_putnbr		\
		Libft/ft_strjoin		\
		Libft/ft_itoa	\
		Libft/ft_split		\
		Libft/ft_strmapi	\
	  printf/ft_printf\
	  printf/ft_printhex\
	  printf/ft_printnum\
	  printf/ft_printstr\
	  printf/ft_contfun\
	  printf/ft_printfsrc\
	  printf/ft_printnumesrc\
	  printf/ft_printhexautils\
	  printf/ft_printwrite\

S = ./
SRCS = $(addprefix $(S), $(addsuffix .c, $(FILES)))
SRCS_B = $(addprefix $(S), $(addsuffix .c, $(FILES_B)))

O = ./
OBJS = $(addprefix $(S), $(addsuffix .o, $(FILES)))
OBJS_B = $(addprefix $(S), $(addsuffix .o, $(FILES_B)))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: $(OBJS_B)
	$(AR) $(NAME) $^

all: $(NAME)

clean: 
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re
