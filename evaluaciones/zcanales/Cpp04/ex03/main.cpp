/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:40:12 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/14 18:40:47 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

int main(void)
{
	
	std::cout << "---------[1️⃣ ]LEARN MATERIALS----------" << std::endl;
	IMateriaSource* src = new MateriaSource();
	AMateria* tmp;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	
	std::cout << std::endl <<"---------[2️⃣ ]CREATE AND EQUIPE MATERIA SOURCE----------" << std::endl;
	ICharacter* me = new Character("me");
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	std::cout << std::endl << "---------[3️⃣ ]USE MATERIALS----------" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);

	std::cout << std::endl << "---------[4️⃣ ]ERRORS HANDLE----------" << std::endl;
	IMateriaSource* src2 = new MateriaSource();
	tmp = src2->createMateria("ice");
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	me->equip(tmp);
	me->unequip(5);
	me->unequip(-1);
	me->use(5, *bob);
	me->use(-1, *bob);
	me->unequip(0);
	me->use(0, *bob);

	std::cout << std::endl << "---------[5️⃣ ]DEEP COPY----------" << std::endl;
	Character a("a");
	tmp = src->createMateria("cure");
	a.equip(tmp); 
	Character b("b");
	tmp = src->createMateria("cure");
	b.equip(tmp);
	a.unequip(0); 
	b = a;
	a.use(0, *bob);
	b.use(0, *bob);
	tmp = src->createMateria("cure");
	a.equip(tmp);
	a.use(0, *bob);
	b.use(0, *bob);


	delete src2;
	delete bob;
	delete me;
	delete src;

	return 0;
}

