/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:40:12 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/18 10:55:19 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <string>

int main(void)
{
	//This would NOT be ok because Animal is abstract. It cannot instanciate a abstract class!!!
    //Animal *a = new Animal();
	Animal *b = new Cat();
	Animal *c = new Dog();

	std::cout << "Animal type: " << b->getType() << std::endl;
	b->makeSound();
	std::cout << "Animal type: " << c->getType() << std::endl;
	c->makeSound();

	delete b;
	delete c;

	return (0);
}

