#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>

class Zombie{
	public:
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void) const;
	private:
		std::string	_name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif
