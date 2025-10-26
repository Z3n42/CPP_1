/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:53:11 by ingonzal          #+#    #+#             */
/*   Updated: 2022/10/02 18:08:45 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << " _________ Subject Main __________" << std::endl;
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
	std::cout << " _________Copy Constructors__________" << std::endl;
	const Dog d = Dog();
	const Cat c = Cat();
	const Animal* h = new Dog(d);
	const Animal* k = new Cat(c);
	std::cout << std::endl;
	std::cout << "h->getType => " << h->getType() << " " << std::endl;
	std::cout << "k->getType => " << k->getType() << " " << std::endl;
	h->makeSound();
	k->makeSound();
	std::cout << std::endl;
	delete(h);
	delete(k);
	std::cout << std::endl;
	std::cout << " _________Wrong Animals__________" << std::endl;
	const WrongAnimal* WrongMeta = new WrongAnimal();
	const WrongAnimal* w = new WrongCat();
	std::cout << std::endl;
	std::cout << "w->getType => " << w->getType() << " " << std::endl;
	std::cout << std::endl;
	WrongMeta->makeSound();
	w->makeSound();
	std::cout << std::endl;
	delete(WrongMeta);
	delete(w);
	std::cout << std::endl;
	std::cout << " _________Wrong Animals Copy Cons__________" << std::endl;
	const WrongCat x = WrongCat();
	const WrongAnimal* y = new WrongCat(x);
	std::cout << std::endl;
	std::cout << "y->getType => " << y->getType() << " " << std::endl;
	std::cout << std::endl;
	y->makeSound();
	std::cout << std::endl;
	delete(y);
	std::cout << std::endl;
	std::cout << " _________Non allocated Destructors__________" << std::endl;
}
