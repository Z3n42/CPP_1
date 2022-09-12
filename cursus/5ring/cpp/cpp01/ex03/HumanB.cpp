/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:37:41 by ingonzal          #+#    #+#             */
/*   Updated: 2022/07/17 14:30:17 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	this->_weapon = NULL;
}
/* Se podría inicializar this->_weapon = NULL en el constructor, pero se comporta igual; */

void HumanB::attack(void)
{
	if (this->_weapon != NULL)
		std::cout << this->_name << " attack with his " << _weapon->get_type() << std::endl; 
	else
		std::cout << this->_name << " attack with his own hands " << std::endl; 
}

void HumanB::setWeapon(Weapon &other_weapon)
{
	this->_weapon = &other_weapon;
}

HumanB::~HumanB(void)
{
	
}
