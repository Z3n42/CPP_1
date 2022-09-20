/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:34:39 by ingonzal          #+#    #+#             */
/*   Updated: 2022/09/04 18:07:18 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

class DiamondTrap : public ScavTrap, public FragTrap{

private:
	std::string _Name;
	static const std::string _Class;
	using FragTrap::_Hitpoints;
	using ScavTrap::_EnergyPoints;
	using FragTrap::_AttackDamage;

public:
	DiamondTrap(void);
	DiamondTrap(std::string name);
	~DiamondTrap(void);
	DiamondTrap(DiamondTrap const &src);

	DiamondTrap & operator=(DiamondTrap const & rhs);
	std::string getClass(void) const;
	using ScavTrap::attack;
	void whoAmI(void);
};
#endif
