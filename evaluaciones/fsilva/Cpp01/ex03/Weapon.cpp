#include "Weapon.hpp"
#include <string>

Weapon::Weapon(const std::string type): type(type)
{
	std::cout << "Weapon " << this->type << " created\n";
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon of type " << this->type << " destroyed\n";
}

void Weapon::setType(std::string type)
{
	this->type = type;
}

const std::string& Weapon::getType(void) const
{
	return (static_cast<const std::string&>(this->type));
}
