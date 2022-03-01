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

#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "WrongDog.hpp"


int main(void)
{
	std::cout << "-------CORRECT ANIMALS-------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "Animal Type: " << j->getType() << " " <<  std::endl;
	std::cout << "Animal Type: " << i->getType() << " " << std::endl;
	j->makeSound(); 
	i->makeSound();
	meta->makeSound();
	std::cout << "-------WRONG ANIMALS-------" << std::endl;
	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* j2 = new WrongDog();
	const WrongAnimal* i2 = new WrongCat();

	std::cout << "Animal Type: " << j2->getType() << " " <<  std::endl;
	std::cout << "Animal Type: " << i2->getType() << " " << std::endl;
	i2->makeSound(); 
	j2->makeSound();
	meta2->makeSound();

	delete meta;
	delete j;
	delete i;
	delete meta2;
	delete j2;
	delete i2;
	return (0);
}
