NAME = Inception

$(NAME):
	@mkdir -p srcs/requirements/mariadb/db_data
	@mkdir -p srcs/requirements/wordpress/wp_data
	@docker-compose -f srcs/docker-compose.yml up -d --build

down:
	@docker-compose -f srcs/docker-compose.yml down --rmi all -v

destroy:
	@docker-compose -f srcs/docker-compose.yml down --rmi all; \
	docker volume rm srcs_db_data; docker volume rm srcs_wp_data; \
	docker system prune -a -f; docker network prune -f; \
	rm -rf srcs/requirements/mariadb/db_data; rm -rf srcs/requirements/wordpress/wp_data;

all: $(NAME)

fclean: down
	@docker network prune -f; \
	docker system prune -a -f

re: fclean all

.PHONY: all destroy down fclean re
