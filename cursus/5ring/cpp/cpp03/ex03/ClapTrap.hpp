/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:32:34 by ingonzal          #+#    #+#             */
/*   Updated: 2022/06/20 18:58:36 by ingonzal         ###   ########.fr       */
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
	static const std::string _Class;

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
	std::string getClass(void) const;

	void setHit(int const new_amount);
	void setEnergy(int const new_amount);
	void setDamage(int const new_amount);

	virtual void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
