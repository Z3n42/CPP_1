/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:56:17 by ingonzal          #+#    #+#             */
/*   Updated: 2022/06/21 21:10:26 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ClapTrap.hpp"

const std::string ClapTrap::_Class = "ClapTrap ";

ClapTrap::ClapTrap(void){
	std::cout << "Unnamed ClapTrap has been summoned." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _Name(name), _Hitpoints(10), _EnergyPoints(10), _AttackDamage(0){
	std::cout << this->_Class << this->_Name << " has been summoned." << std::endl;
}
ClapTrap::ClapTrap(std::string name, unsigned int Hitpoints, unsigned int EnergyPoints, unsigned int AttackDamage){
	this->_Name = name;	
	this->_Hitpoints = Hitpoints;	
	this->_EnergyPoints = EnergyPoints;	
	this->_AttackDamage = AttackDamage;	
	std::cout << this->_Class << this->_Name << " has been summoned." << std::endl;

}

ClapTrap::~ClapTrap(void){
	std::cout << this->_Class  << this->_Name << " has been destroyed." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src){
	*this = src;	
	std::cout << this->_Class << this->_Name << " has been copied." << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs){
	std::cout << this->_Class << this->_Name << " Equlized to " << rhs._Class << rhs._Name << std::endl;
	this->_Name = rhs._Name;	
	this->_Hitpoints = rhs._Hitpoints;	
	this->_EnergyPoints = rhs._EnergyPoints;	
	this->_AttackDamage = rhs._AttackDamage;	

	return(*this);
}

std::string ClapTrap::getname(void) const{
	return(this->_Name);
}

int  ClapTrap::getHit(void) const{
	return(this->_Hitpoints);
}

int ClapTrap::getEnergy(void) const{
	return(this->_EnergyPoints);
}

int ClapTrap::getDamage(void) const{
	return(this->_AttackDamage);
}

std::string ClapTrap::getClass(void) const{
	return(this->_Class);
}

void ClapTrap::setHit(int const new_amount){
	this->_Hitpoints = new_amount;
}
	
void ClapTrap::setEnergy(int const new_amount){
	this->_EnergyPoints = new_amount;
}

void ClapTrap::attack(std::string const & target){
	std::cout << this->_Class  << this->_Name;
	std::cout << " attacks " << target;
	std::cout << ",  causing " << this->_AttackDamage;
	std::cout << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	std::cout << this->_Class  << this->_Name;
	std::cout << " take " << amount;
	std::cout << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	std::cout << this->_Class << this->_Name;
	std::cout << " has been repaired " << amount;
	std::cout << " points of damage!" << std::endl;
}
