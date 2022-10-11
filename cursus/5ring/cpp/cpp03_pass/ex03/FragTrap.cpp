/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:46:27 by ingonzal          #+#    #+#             */
/*   Updated: 2022/10/08 19:06:34 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <unistd.h>

const std::string FragTrap::_Class = "FragTrap ";

FragTrap::FragTrap(void){
	std::cout << "Unnamed FragTrap has been summoned." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30){
	this->_Hitpoints = 100;
	this->_AttackDamage = 30;
	std::cout << this->_Class << this->_Name << " has been summoned." << std::endl;
}

FragTrap::~FragTrap(void){
	std::cout << this->_Class << this->_Name << " has been destroyed." << std::endl;
}

FragTrap::FragTrap(FragTrap const &src){
	*this = src;	
	std::cout << this->_Class << this->_Name << " has been copied." << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs){
	std::cout << this->_Class << this->_Name << " Equlized to " << rhs._Class << rhs._Name << std::endl;
	this->_Name = rhs._Name;	
	this->_Hitpoints = rhs._Hitpoints;	
	this->_EnergyPoints = rhs._EnergyPoints;	
	this->_AttackDamage = rhs._AttackDamage;	

	return(*this);
}

std::string FragTrap::getClass(void) const{
	return(this->_Class);
}

void FragTrap::attack(std::string const & target){
	std::cout << this->_Class  << this->_Name;
	std::cout << " attacks " << target;
	std::cout << ",  causing " << this->_AttackDamage;
	std::cout << " points of damage!" << std::endl;
}

void FragTrap::highFiveGuys(void){
	std::cout << std::endl;
	std::cout << this->_Class <<  "*SPECIAL*" << std::endl;
	std::cout << this->_Name;
	std::cout << " is asking Who is the PAPA" << std::endl;
	sleep(2);
	std::cout << "Give me yor best High five if you are the big PAPA.." << std::endl;
	sleep(2);
	std::cout << "Yes u are.." << std::endl;
	sleep(2);
	std::cout << "Give me the best.." << std::endl;
	sleep(2);
	std::cout << "I'm  still waiting.." << std::endl;
	sleep(2);
	std::cout << "No????" << std::endl;
	sleep(2);
	std::cout << "Anyone????????" << std::endl;
	sleep(2);
	std::cout << "Ok, I'm done.." << std::endl;
	sleep(2);
	std::cout << "So... Am i the big PAPA..? Maybe???" << std::endl;
	sleep(3);
	std::cout << std::endl;
}
