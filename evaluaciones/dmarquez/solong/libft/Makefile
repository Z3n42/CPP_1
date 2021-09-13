# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 15:05:23 by dmarquez          #+#    #+#              #
#    Updated: 2021/08/25 11:13:19 by dmarquez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
	ft_tolower.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
	ft_strncmp.c ft_atoi.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c\
	ft_memcmp.c ft_calloc.c ft_strdup.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_split.c ft_abs_nbr.c ft_nbr_len.c\
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
	ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS = $(SRC:.c=.o)
INCLUDE = ./ft_printf


LIB = ar rcs
CC = gcc
CFLAGS = -Wall -Werror -Wextra

RM = rm -f

%.o : %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS) $(INCLUDE)
	@make -C $(INCLUDE)
	@cp ft_printf/libftprintf.a .
	@mv libftprintf.a $(NAME)
	@$(LIB) $(NAME) $(OBJS)
	@echo "\033[92mMandatory Libft assambled Master\033[0m"

all : $(NAME)

clean :
	@$(RM) $(OBJS)
#	@echo "\033[34mlibft temporary files cleaned\033[0m"
	@make clean -C ./ft_printf

fclean : clean
	@$(RM) $(NAME) $(BONUS_OBJS)
	@make fclean -C ./ft_printf

re : msgre fclean msg all

msg :
	@echo Compiling...

msgre :
	@echo Your wish is my command Master

.PHONY: all clean fclean re msg msgre
