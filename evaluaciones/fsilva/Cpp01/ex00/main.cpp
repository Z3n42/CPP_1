#include "Zombie.hpp"

int	main()
{
	Zombie* zombiePtr;

	zombiePtr = newZombie("Red");
	randomChump("fooooo");
	delete zombiePtr;
	return (0);
}
