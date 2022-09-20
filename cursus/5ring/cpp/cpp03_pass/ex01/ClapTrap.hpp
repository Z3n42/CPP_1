/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:32:34 by ingonzal          #+#    #+#             */
/*   Updated: 2022/06/21 21:02:12 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

class ClapTrap{

private:
	static const std::string _Class;

protected:
	std::string _Name;
	unsigned int _Hitpoints;
	unsigned int _EnergyPoints;
	unsigned int _AttackDamage;

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(std::string name, unsigned int Hitpoints, unsigned int EnergyPoints, unsigned int AttackDamage);
	~ClapTrap(void);
	ClapTrap(ClapTrap const &src);

	ClapTrap & operator=(ClapTrap const & rhs);

	std::string getname(void) const;
	int getHit(void) const;
	int getEnergy(void) const;
	int getDamage(void) const;
	std::string getClass(void) const;

	void setHit(int const new_amount);
	void setEnergy(int const new_amount);
	void setDamage(int const new_amount);

	void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
