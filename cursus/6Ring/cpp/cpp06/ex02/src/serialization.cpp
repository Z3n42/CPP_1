/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:58:35 by ingonzal          #+#    #+#             */
/*   Updated: 2023/06/30 20:01:20 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialization.hpp"
#include <iomanip>

Base::~Base(void){

}

Base * generate(void){
	int index;
	srand (time(NULL));
	index = rand () % 3;

	if (index < 1){
		std::cout << "Generate A Class" << std::endl;
		return (dynamic_cast<Base*>(new A()));
	}
	else if (index > 1){
		std::cout << "Generate B Class" << std::endl;
		return (dynamic_cast<Base*>(new B()));
	}
	else{
		std::cout << "Generate C Class" << std::endl;
		return (dynamic_cast<Base*>(new C()));
	}
}

void identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "It's A pointer" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "It's B pointer" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "It's C pointer" << std::endl;
}

void identify(Base& p){
	A a;
	B b;
	C c;

	try{
		a = dynamic_cast<A&>(p);
		std::cout << "It's A reference" << std::endl;
	}
	catch (std::exception e){
		try{
			b = dynamic_cast<B&>(p);
			std::cout << "It's B reference" << std::endl;
		}
		catch (std::exception e){
			try{
				c = dynamic_cast<C&>(p);
				std::cout << "It's C reference" << std::endl;
			}
			catch (std::exception e){
				std::cout << "ERROR" << std::endl;
			}
		}
	}
}
