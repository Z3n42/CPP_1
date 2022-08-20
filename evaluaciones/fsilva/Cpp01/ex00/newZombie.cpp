#include "Zombie.hpp"
#include <string>

Zombie*	newZombie(std::string name)
{
	Zombie* zombiePtr = new Zombie(name);
	zombiePtr->announce();
	return (zombiePtr);
}
