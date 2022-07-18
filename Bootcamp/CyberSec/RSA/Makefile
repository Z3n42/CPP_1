NAME = corsair

CC = gcc
CFLAGS = -Wextra -Werror -Wall -g3 -fsanitize=address
RM = rm -rf
OPENSSL_LIB = /Volumes/Macintosh\ HD/sgoinfre/goinfre/Perso/${USER}/homebrew/opt/openssl@3/lib
OPENSSL_INC = /Volumes/Macintosh\ HD/sgoinfre/goinfre/Perso/${USER}/homebrew/opt/openssl@3/include/ 
SSL_FLAG = -lssl -lcrypto

#SSL_FLAG =  -I$(OPENSSL_INC)

SRC = main.c
OBJ = $(SRC:.c=.o)

%.o:%.c
	$(CC) $(CFLAGS) -I$(OPENSSL_INC) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(SSL_FLAG) -L$(OPENSSL_LIB)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean re fclean all
