#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class HumanB{
	public:
		HumanB(std::string name);
		~HumanB(void);
		void	setWeapon(Weapon& weaponREF);
		void	attack(void) const;

	private:
		Weapon*		weaponPtr;
		std::string	name;
};

#endif
