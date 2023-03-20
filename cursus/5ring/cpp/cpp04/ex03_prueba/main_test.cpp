/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:14:26 by ingonzal          #+#    #+#             */
/*   Updated: 2023/03/20 13:10:43 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main(void)
{
	// Constructors
	std::cout << std::endl;
	std::cout << "CONSTRUCTORS:" << std::endl;
	std::cout << "-----------------------" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	std::cout << std::endl;

	// Create Materia
	std::cout << "CREATE MATERIA:" << std::endl;
	std::cout << "-----------------------" << std::endl;
	AMateria	*tmp;
	
	AMateria	*tmp1;
	AMateria	*tmp2;
	AMateria	*tmp3;
	AMateria	*tmp4;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp1 = src->createMateria("cure");
	me->equip(tmp1);
	tmp = src->createMateria("fire"); // null
	me->equip(tmp);
	std::cout << std::endl;

	// Use on a new character
	std::cout << "USE ON A NEW CHARACTER:" << std::endl;
	std::cout << "-----------------------" << std::endl;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;
	me->use(2, *bob); // Use an empty / non existing slot in inventory
	me->use(-4, *bob);
	me->use(18, *bob);
	std::cout << std::endl;

	// Deep copy character
	std::cout << "DEEP COPY CHARACTER:" << std::endl;
	std::cout << "-----------------------" << std::endl;
	Character	*Cloud = new Character("Cloud");
	tmp2 = src->createMateria("cure");
	Cloud->equip(tmp2);
	tmp3 = src->createMateria("ice");
	Cloud->equip(tmp3);
	tmp = src->createMateria("earth");
	Cloud->equip(tmp);
	Character	*Cloud_copy = new Character(*Cloud);
	std::cout << std::endl;

	// Deep copy vs its source character
	std::cout << "DEEP COPY VS SOURCE:" << std::endl;
	std::cout << "-----------------------" << std::endl;
	Cloud->unequip(0); // this shows that they have different materia pointers equipped
	tmp4 = Cloud_copy->getMateria(1);
	Cloud_copy->unequip(1); //this will produce a leak if we don't store the address somewhere else before
	delete tmp4;
	tmp = src->createMateria("cure");
	Cloud_copy->equip(tmp);
	tmp = src->createMateria("ice");
	Cloud_copy->equip(tmp);
	std::cout << std::endl;

	Cloud->use(0, *bob);
	Cloud->use(1, *bob);
	Cloud->use(2, *bob);
	Cloud->use(3, *bob);
	std::cout << std::endl;
	Cloud_copy->use(0, *bob);
	Cloud_copy->use(1, *bob);
	Cloud_copy->use(2, *bob);
	Cloud_copy->use(3, *bob);
	std::cout << std::endl;

	// Unequip tests:
	std::cout << "UNEQUIP:" << std::endl;
	std::cout << "-----------------------" << std::endl;
	me->unequip(-1); // unequip an empty / non existing slot in inventory
	me->unequip(18);
	me->unequip(3);
	std::cout << std::endl;
	me->use(1, *Cloud);
	me->unequip(1); // Unequip a valid slot in inventory (cure unequipped)
	me->use(1, *Cloud); // try to use it
	std::cout << std::endl;

	// Destructors
	std::cout << "DESTRUCTORS:" << std::endl;
	std::cout << "-----------------------" << std::endl;
	delete bob;
	delete me;
	delete src;
	delete Cloud;
	delete Cloud_copy;
	delete tmp1;
	delete tmp2;
	std::cout << std::endl;

	// Leaks check
	std::cout << "LEAKS:" << std::endl;
	std::cout << "-----------------------" << std::endl;
	system("leaks FFVII_Test");
	return (0);
}
