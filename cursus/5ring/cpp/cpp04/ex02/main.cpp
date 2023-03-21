/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:53:11 by ingonzal          #+#    #+#             */
/*   Updated: 2023/03/21 20:13:28 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	/* const AAnimal* meta = new AAnimal(); */
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	std::cout << std::endl;
	std::cout << "j->getType => " << j->getType() << " " << std::endl;
	std::cout << "i->getType => " << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	/* meta->makeSound(); */
	std::cout << std::endl;
	/* delete(meta); */
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

	std::cout << std::endl;
	std::cout << "__________ Leaks Summary _________" << std::endl;
	std::cout << std::endl;
	system("leaks Animals_02");
	std::cout << std::endl;
}
