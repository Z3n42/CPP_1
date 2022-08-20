#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name): _name(name)
{
	
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie " << this->_name << " has been destroyed\n";
}

void	Zombie::announce(void) const
{
	std::cout << this->_name << " BraiiiiiiinnnnzzzZ..." << std::endl;
}
