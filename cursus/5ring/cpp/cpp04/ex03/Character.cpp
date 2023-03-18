/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:43:26 by ingonzal          #+#    #+#             */
/*   Updated: 2023/03/11 19:30:54 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void){
	std::cout << "Misterious character joined to the party" << std::endl;
}

Character::Character(std::string name) : _name(name){

	int i;
	i = 0;

	std::cout << _name << " joined to the party" << std::endl;
	while(i < 4)
	{
		this->_inventory[i] = 0;
		i++;
	}
}

Character::~Character(void){

	int i;
	i = 0;

	while(i < 4)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		i++;
	}
	std::cout << this->_name << " is dead"<< std::endl;
}


Character::Character(Character const & src) : _name(src.getName() + "_doppelganger"){

	int i;
	i = 0;

	while(i < 4)
	{
		if ((src._inventory)[i])
			(this->_inventory)[i] = (src._inventory[i])->clone();
		i++;
	}
	std::cout << _name << " joined to the party" << std::endl;
}

Character & Character::operator=(Character const & rhs){

	int i;
	i = 0;

	while(i < 4)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (rhs._inventory[i])
			this->_inventory[i] = (rhs._inventory[i])->clone();
		i++;
	}
	return (*this);
}

std::string const & Character::getName() const{
	return (this->_name);
}

void Character::equip(AMateria* m){

	int i;
	i = 0;

	if (!m)
	{
		std::cout << this->_name << " has an empty inventory" << std::endl;
		return ;
	}
	while ((this->_inventory)[i] != 0 && i < 4)
		i++;
	if (i >= 4)
		std::cout << this->_name << " too much materia equiped" << std::endl;
	else
	{
		(this->_inventory)[i] = m;
		std::cout << this->_name << " equipped " << m->getType() << " at " << i << std::endl;
	}
}

void Character::unequip(int idx){

	if (idx < 0 || idx >= 4)
		std::cout << this->_name << " has an empty inventory" << std::endl;
	else if (!(this->_inventory)[idx])
		std::cout << this->_name << " inventory slot " << idx << " it's empty" << std::endl;
	else
	{
		AMateria *m = (this->_inventory)[idx];
		std::cout << this->_name << " unequipped " << m->getType() << " at slot "<< idx  << std::endl;
		(this->_inventory)[idx] = 0;
	}
}

void Character::use(int idx, ICharacter& target){

	std::string	name = this->getName();

	if (idx < 0 || idx >= 4 || !(this->_inventory)[idx])
		std::cout << idx << " inventory slot is empty" << std::endl;
	else
	{
		std::cout << name;
		((this->_inventory)[idx])->use(target);
	}
}

AMateria	*Character::getMateria(int idx){
		return (this->_inventory)[idx];
}
