NAME = ft_transcendence

$(NAME):
	@docker compose -f docker-compose.yml up -d --build

down:
	@docker compose -f docker-compose.yml down

restart: down all

destroy:
	@docker compose -f docker-compose.yml down --rmi all --remove-orphans -v; \
	docker system prune -a -f; docker network prune -f

all: $(NAME)

fclean: down
	@docker network prune -f; \
	docker system prune -a -f

help:
	@echo "Available commands:"
	@echo "  make         		- Starts services and builds necessary images."
	@echo "  make down    		- Stops services."
	@echo "  make restart 		- Stops services and restarts services again."
	@echo "  make destroy 		- Performs a full cleanup of the Docker environment."
	@echo "  make all     		- Alias for 'make'."
	@echo "  make fclean  		- Cleans the Docker environment."
	@echo "  make re      		- Rebuilds everything from scratch."
	@echo "  make prod    		- Starts production environment services."
	@echo "  make prod-down		- Stops production services."
	@echo "  make prod-restart	- Stops production services and restarts production services again."
	@echo "  make prod-destroy	- Perform a full cleanup of the Docker production services."

re: destroy all

prod:
	@docker compose -f docker-compose.prod.yml up -d --build

prod-down:
	@docker compose -f docker-compose.prod.yml down

prod-restart: prod-down prod

prod-destroy:
	@docker compose -f docker-compose.prod.yml down --rmi all --remove-orphans -v; \
	docker system prune -a -f; docker network prune -f

.PHONY: all destroy down fclean re prod prod-down prod-destroy prod-restart
