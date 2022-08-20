#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"
# include <string>

class HumanA{
	public:
		HumanA(const std::string name, Weapon& weaponREF);
		~HumanA(void);
		void	attack(void) const;

	private:
		Weapon&		  weaponREF;
		std::string  name;
};
#endif
