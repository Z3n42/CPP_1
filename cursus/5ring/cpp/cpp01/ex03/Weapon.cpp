/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:16:40 by ingonzal          #+#    #+#             */
/*   Updated: 2022/04/27 19:27:31 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{

}

Weapon::~Weapon()
{

}

std::string	const &Weapon::get_type()
{
	return (this->_type);
}

void	Weapon::setType(std::string other_type)
{
	this->_type = other_type;
}
