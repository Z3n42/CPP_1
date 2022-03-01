/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:01:46 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/16 16:32:32 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(void){};
Weapon::Weapon(std::string type)
{
	_type = type;	
}

const std::string &Weapon::getType(void)
{
	return (_type);
};

void Weapon::setType(std::string type)
{
	_type = type;
	return;
};
