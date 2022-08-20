#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon{
	public:
		Weapon(const std::string type);
		~Weapon();
		const std::string&	getType(void) const;
		void				setType(std::string type);
	private:
		std::string	type;
};

#endif
