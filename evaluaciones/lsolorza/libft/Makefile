# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsolorza <lsolorza@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 18:01:19 by lsolorza          #+#    #+#              #
#    Updated: 2021/06/22 18:51:51 by lsolorza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_memset.c		\
	   ft_bzero.c		\
	   ft_memcpy.c		\
	   ft_memccpy.c		\
	   ft_memmove.c 	\
	   ft_memchr.c		\
	   ft_memcmp.c		\
	   ft_strlen.c		\
	   ft_isalpha.c 	\
	   ft_isdigit.c		\
	   ft_isalnum.c		\
	   ft_isascii.c		\
	   ft_isprint.c		\
	   ft_toupper.c		\
	   ft_tolower.c		\
	   ft_strchr.c		\
	   ft_strrchr.c		\
	   ft_strncmp.c		\
	   ft_strlcpy.c		\
	   ft_strlcat.c		\
	   ft_strnstr.c		\
	   ft_atoi.c		\
	   ft_calloc.c		\
	   ft_strdup.c		\
	   ft_substr.c		\
	   ft_strjoin.c		\
	   ft_strtrim.c		\
	   ft_itoa.c		\
	   ft_split.c		\
	   ft_strmapi.c		\
	   ft_putchar_fd.c	\
	   ft_putstr_fd.c	\
	   ft_putendl_fd.c	\
	   ft_putnbr_fd.c	\

NAME = libft.a

OBJS = $(SRCS:.c=.o)

BONUS = ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstdelone.c		\
		ft_lstclear.c		\
		ft_lstiter.c		\

BONUS_OBJS = $(BONUS:.c=.o)

CC = clang

CC_FLAGS = -Wall -Wextra -Werror

all: $(NAME)
$(NAME): $(OBJS)
	@ar r $(NAME) $(OBJS)
	@echo "Libft Done !"

clean:
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJS) $(BONUS_OBJS)
	@ar r $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo "Libft Bonus done!!"
.PHONY: all clean fclean re bonus
