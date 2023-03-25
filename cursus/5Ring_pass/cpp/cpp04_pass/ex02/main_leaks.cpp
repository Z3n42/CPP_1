/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_leaks.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:05:41 by ingonzal          #+#    #+#             */
/*   Updated: 2023/02/26 16:45:19 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <stdlib.h>

int	main(void)
{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	std::cout << std::endl;

	delete j;
	delete i;
	std::cout << std::endl;
	std::cout << "__________ Leaks Summary _________" << std::endl;
	std::cout << std::endl;
	system("leaks Animals_02");
	std::cout << std::endl;
	std::cout << "__________________________________" << std::endl;
}
