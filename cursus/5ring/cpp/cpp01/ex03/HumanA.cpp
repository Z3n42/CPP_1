/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:37:41 by ingonzal          #+#    #+#             */
/*   Updated: 2022/04/27 19:13:34 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{

}

void HumanA::attack(void)
{
	std::cout << this->_name << " attack with his " << _weapon.get_type() << std::endl; 
}

HumanA::~HumanA(void)
{
	
}
