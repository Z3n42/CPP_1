/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:39:24 by ingonzal          #+#    #+#             */
/*   Updated: 2023/04/19 21:36:22 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat *alloc = NULL;
	Bureaucrat *OverAlloc = NULL;
	Bureaucrat *UnderAlloc = NULL;
	try{
		std::cout << "Constructor" << std::endl;
		Bureaucrat a("pepe", 23);
		std::cout << "==================================" << std::endl;
		std::cout << "Copy Constructor And Assignation Overload" << std::endl;
		Bureaucrat f(a);
		std::cout << "==================================" << std::endl;
		std::cout << "Operator Overload" << std::endl;
		std::cout << f << std::endl;
		std::cout << "==================================" << std::endl;
		std::cout << "++++++++ Usual Exceptions ++++++++" << std::endl;
		Bureaucrat b("paco", 15555);
		std::cout << "==================================" << std::endl;
		alloc = new Bureaucrat ("pupu", 222);
		Bureaucrat e("pipo", 19);
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
	/* try{ */
	/* 	std::cout << "Allocated Exceptions" << std::endl; */
	/* 	std::cout << "=============================" << std::endl; */
	/* catch (std::exception & e){ */
	/* 	std::cout << e.what() << std::endl; */
	/* } */
	/* try{ */
	/* 	std::cout << "Allocated Exceptions" << std::endl; */
	/* 	std::cout << "=============================" << std::endl; */
	/* catch (std::exception & e){ */
	/* 	std::cout << e.what() << std::endl; */
	/* } */
	delete alloc;
	delete UnderAlloc;
	delete OverAlloc;
}
