#include "HumanA.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

HumanA::HumanA(const std::string name, Weapon& weaponREF): 
						weaponREF(weaponREF), name(name)
{
	std::cout << "HumanA " << this->name << " with weapon "
			<< this->weaponREF.getType() << " created\n";
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA " << this->name << " destroyed\n";
}

void HumanA::attack(void) const
{
	std::cout << this->name << " attacks with his " << this->weaponREF.getType()
				<< std::endl;
}
