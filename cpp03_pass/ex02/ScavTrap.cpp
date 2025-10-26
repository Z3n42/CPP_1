/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:56:17 by ingonzal          #+#    #+#             */
/*   Updated: 2022/06/21 19:42:54 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ScavTrap.hpp"

const std::string ScavTrap::_Class = "ScavTrap ";

ScavTrap::ScavTrap(void){
	std::cout << "Unnamed ScavTrap has been summoned." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20){
	std::cout << this->_Class << this->_Name << " has been summoned." << std::endl;
}

ScavTrap::~ScavTrap(void){
	std::cout << this->_Class << this->_Name << " has been destroyed." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src){
	*this = src;	
	std::cout << this->_Class << this->_Name << " has been copied." << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs){
	std::cout << this->_Class << this->_Name << " Equlized to " << rhs._Class << rhs._Name << std::endl;
	this->_Name = rhs._Name;	
	this->_Hitpoints = rhs._Hitpoints;	
	this->_EnergyPoints = rhs._EnergyPoints;	
	this->_AttackDamage = rhs._AttackDamage;	

	return(*this);
}

void ScavTrap::attack(std::string const & target){
	std::cout << this->_Class  << this->_Name;
	std::cout << " attacks " << target;
	std::cout << ",  causing " << this->_AttackDamage;
	std::cout << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(){
	std::cout << "**" << this->_Class  << this->_Name;
	std::cout << " have enterred in Gate Keeper mode." << std::endl;
}
