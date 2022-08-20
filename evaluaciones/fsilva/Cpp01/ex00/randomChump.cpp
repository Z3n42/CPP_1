#include "Zombie.hpp"
#include <string>

void	randomChump(std::string name)
{
	Zombie	tempZombie(name);

	tempZombie.announce();
	return ;
}
