#include "Zombie.hpp"
#include <string>
int main()
{
	std::string name = "marupili";
	int	nbZombies = 10;

	Zombie* zombies = zombieHorde(nbZombies, name);
	for (int i = 0; i < nbZombies; i++)
		zombies[i].announce();
	for (int i = nbZombies - 1; i >=0; i--){
		zombies[i].~Zombie();
	}
	operator delete[](zombies);
	return(0);
}
