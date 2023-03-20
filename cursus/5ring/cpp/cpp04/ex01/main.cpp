/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:53:11 by ingonzal          #+#    #+#             */
/*   Updated: 2023/03/20 21:22:47 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;
	std::cout << "j->getType => " << j->getType() << " " << std::endl;
	std::cout << "i->getType => " << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;
	delete(meta);
	delete(j);
	delete(i);
	std::cout << std::endl;
	std::cout << " _________Wrong Animals__________" << std::endl;
	const WrongAnimal* WrongMeta = new WrongAnimal();
	const WrongAnimal* w = new WrongCat();
	std::cout << "w->getType => " << w->getType() << " " << std::endl;
	WrongMeta->makeSound();
	w->makeSound();
	delete(WrongMeta);
	delete(w);

	/* Dog basic; */
	/* { */
	/* 	Dog tmp = basic; */
	/* } */
	/* basic.getIdeasFromBrain(); */

	/* std::cout << std::endl; */
	/* std::cout << "__________ Leaks Summary _________" << std::endl; */
	/* std::cout << std::endl; */
	/* system("leaks Animals_01"); */
	/* std::cout << std::endl; */
}
