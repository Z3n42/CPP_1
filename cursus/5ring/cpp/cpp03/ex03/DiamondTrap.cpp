/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:44:04 by ingonzal          #+#    #+#             */
/*   Updated: 2022/06/23 18:31:41 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

const std::string DiamondTrap::_Class = "DiamondTrap ";

DiamondTrap::DiamondTrap(void){
	std::cout << "Unnamed DiamondTrap has been summoned." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_scav_name"), FragTrap(name + "_frag_name"){
	this->_Name = name;
	std::cout << this->_Class << this->_Name << " has been summoned." << std::endl;
}

DiamondTrap::~DiamondTrap(void){
	std::cout << this->_Class << this->_Name << " has been destroyed." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src){
	*this = src;	
	std::cout << this->_Class << this->_Name << " has been copied." << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & rhs){
	std::cout << this->_Class << this->_Name << " Equlized to " << rhs._Class << rhs._Name << std::endl;
	this->_Name = rhs._Name;	
	this->_Hitpoints = rhs._Hitpoints;	
	this->_EnergyPoints = rhs._EnergyPoints;	
	this->_AttackDamage = rhs._AttackDamage;	

	return(*this);
}

std::string DiamondTrap::getClass(void) const{
	return(this->_Class);
}

void DiamondTrap::whoAmI(void){
	std::cout << std::endl;
	std::cout << this->_Class <<  "*SPECIAL*" << std::endl;
	std::cout << "DiamondTrap's name is " << this->_Name << std::endl;
	std::cout << "ClapTrap's name is " << this->getname() << std::endl;
	std::cout << std::endl;

	/* std::cout << this->_Class << this->_Name << std::endl; */
}
