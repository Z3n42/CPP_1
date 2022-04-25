/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:59:25 by ingonzal          #+#    #+#             */
/*   Updated: 2022/04/22 18:58:26 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

void Zombie::announce(void)
{
	std::cout << '<' << Zombie::_name << '>' <<  " BraiiiiiiinnnzzzZ..." << std::endl;
}
/* Se puede usar this->_name */

Zombie::Zombie(std::string name) : _name(name)
{
	announce();
}

Zombie::Zombie(){

}

Zombie::~Zombie()
{
	std::cout << '<' << Zombie::_name << '>' << " Dying..." << std::endl;

}
