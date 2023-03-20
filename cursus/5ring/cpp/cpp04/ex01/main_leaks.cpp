/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:05:41 by ingonzal          #+#    #+#             */
/*   Updated: 2023/03/20 21:20:59 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <stdlib.h>

int	main(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;

	delete j;
	delete i;

	/* Cat basic; */
	/* { */
	/* 	Cat tmp = basic; */
	/* } */
	/* basic.getIdeasFromBrain(); */

	std::cout << std::endl;
	std::cout << "__________ Leaks Summary _________" << std::endl;
	std::cout << std::endl;
	system("leaks Animals_01");
	std::cout << std::endl;
	std::cout << "__________________________________" << std::endl;
}
