# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 20:57:01 by xamayuel          #+#    #+#              #
#    Updated: 2022/04/04 18:13:17 by xamayuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER   = server
CLIENT   = client 

SERVER_BONUS   = server_bonus
CLIENT_BONUS   = client_bonus

CC	     = gcc
FLAGS    = -Wall -Werror -Wextra

RESET			= 	\033[0m
GREEN 			= 	\033[38;5;46m
WHITE 			= 	\033[38;5;15m
GREY 			= 	\033[38;5;8m
ORANGE 			= 	\033[38;5;202m
RED 			= 	\033[38;5;160m

all : $(SERVER) $(CLIENT)

$(SERVER) : server.o ft_itoa.o ft_strings.o 
	@$(CC)  server.o  ft_itoa.o ft_strings.o -o $@
	@printf "\e[38;5;226m./$@ successfully build\e[0m\n"

$(CLIENT) : client.o ft_client.o  ft_digits.o ft_strings.o
	@$(CC)  client.o ft_client.o  ft_digits.o ft_strings.o -o $@
	@printf "\e[38;5;46m./$@ successfully build🥝\e[0m\n"

$(SERVER_BONUS) : server_bonus.o ft_itoa_bonus.o ft_strings_bonus.o 
	@$(CC)  server_bonus.o  ft_itoa_bonus.o ft_strings_bonus.o -o server
	@printf "\e[38;5;226m./$@ successfully build\e[0m\n"

$(CLIENT_BONUS) : client_bonus.o ft_client_bonus.o  ft_digits_bonus.o ft_strings_bonus.o
	@$(CC)  client_bonus.o ft_client_bonus.o  ft_digits_bonus.o ft_strings_bonus.o -o client
	@printf "\e[38;5;46m./$@ successfully build🥝\e[0m\n"


%.o : %.c
	@echo "$(GREY)Compiling.............................$(ORANGE)$<"
	@$(CC) $(FLAGS) $< -c -I includes
	@echo "$(GREEN)DONE!$(GREY)"
	@sleep .4	

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

clean :
	@rm -f *.o
	@printf "\e[38;5;206m.o files deleted🚽\e[0m\n"

fclean: clean
	@rm -rf $(SERVER) $(CLIENT)
	@rm -rf $(SERVER_BONUS) $(CLIENT_BONUS)
	@printf "\e[38;5;200mBinaries deleted🗑\e[0m\n"

re: fclean all 
