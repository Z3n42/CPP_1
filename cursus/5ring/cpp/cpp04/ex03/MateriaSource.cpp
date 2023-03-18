/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:21:35 by ingonzal          #+#    #+#             */
/*   Updated: 2023/03/11 20:07:56 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource(void){

	int i;
	i = 0;

	std::cout << "Materia source spell" << std::endl;
	while(i < 4)
	{
		this->_inventory[i] = NULL;
		i++;
	}
}

MateriaSource::MateriaSource(MateriaSource const & src){

	int i;
	i = 0;

	while(i < 4)
	{
		if (src._inventory[i])
			this->_inventory[i] = (src._inventory[i])->clone();
		i++;
	}
	std::cout << "Materia source duplicated" << std::endl;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs){

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

MateriaSource::~MateriaSource(void){

	int i;
	i = 0;

	while(i < 4)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		i++;
	}
	std::cout << "Materia source unspell" << std::endl;
}

void MateriaSource::learnMateria(AMateria *m)
{
	int i;
	i = 0;

	while ((this->_inventory)[i] != NULL && i < 4)
		i++;
	if (i >= 4)
	{
		std::cout << "SpellBook full" << std::endl;
		return ;
	}
	else
	{
		(this->_inventory)[i] = m;
		std::cout << m->getType() << " Materia learned"  << std::endl;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i;
	i = 0;

	while ((this->_inventory)[i] && ((this->_inventory)[i])->getType() != type && i < 4)
		i++;
	if (i >= 4 || !(this->_inventory)[i])
	{
		std::cout << type << " not exist"  << std::endl;
		return (NULL);
	}
	else
	{
		std::cout << type << " Materia created"  << std::endl;
		return (((this->_inventory)[i])->clone());
	}
}
