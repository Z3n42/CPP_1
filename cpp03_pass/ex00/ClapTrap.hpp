/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:32:34 by ingonzal          #+#    #+#             */
/*   Updated: 2022/09/04 17:59:53 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class ClapTrap{

private:
	std::string _Name;
	unsigned int _Hitpoints;
	unsigned int _EnergyPoints;
	unsigned int _AttackDamage;

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	~ClapTrap(void);
	ClapTrap(ClapTrap const &src);

	ClapTrap & operator=(ClapTrap const & rhs);

	std::string getname(void) const;
	int getHit(void) const;
	int getEnergy(void) const;
	int getDamage(void) const;

	void setHit(int const new_amount);
	void setEnergy(int const new_amount);
	void setDamage(int const new_amount);

	void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
