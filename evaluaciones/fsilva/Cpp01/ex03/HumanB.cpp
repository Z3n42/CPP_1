#include "HumanB.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

HumanB::HumanB(std::string name): weaponPtr(NULL), name(name)
{
	std::cout << "HumanB " << this->name
		<< " with no weapon created\n";
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB " << this->name << " destroyed\n";
}

void HumanB::setWeapon(Weapon& weaponREF)
{
	this->weaponPtr = &weaponREF;
}

void HumanB::attack(void) const
{
	std::cout << this->name; 
	if (this->weaponPtr == NULL)
		std::cout << " attacks with no weapon\n";
	else
		std::cout << " attacks with his " << this->weaponPtr->getType() 
					<< std::endl;
}
