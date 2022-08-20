#include "Zombie.hpp"
/* #include <string> */

Zombie*	zombieHorde(int N, std::string name)
{
	/*
	void* zombieMem = operator new[] (sizeof (Zombie) * N);
	Zombie *zombies = static_cast<Zombie *>(zombieMem);
	*/
	Zombie *zombies =static_cast<Zombie *>(operator new[] (sizeof (Zombie) * N));
	for (int i = 0; i < N; i++){
		new (&zombies[i]) Zombie(name);
	}
	return (zombies);
}
