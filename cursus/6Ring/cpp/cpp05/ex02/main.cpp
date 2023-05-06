/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:39:24 by ingonzal          #+#    #+#             */
/*   Updated: 2023/05/06 20:01:10 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
	Bureaucrat *alloc = NULL;
	Bureaucrat *signer = NULL;
	Bureaucrat *noSigner = NULL;
	ShrubberyCreationForm *form = NULL;

	try{ 
		std::cout << "+++++++++++++++++++ Allocated ++++++++++++++++++++" << std::endl;
		alloc = new Bureaucrat("Alloc", 137);
		signer = new Bureaucrat("Signer", 145);
		form = new ShrubberyCreationForm ("FormAlloc", "Alloc");
		std::cout << "==================================================" << std::endl;
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try{
		std::cout << std::endl; 
		std::cout << "++++++++++++ Constructor Excepts +++++++++++++++" << std::endl;
		/* AForm a("B42-WgradeHigh", 0, 150); */
		signer->signForm(*form);
		form->execute(*alloc);
		std::cout << std::endl;
	}
	catch (std::exception & e){
		std::cout << "++++++++++++++++++ WGradeHigh ++++++++++++++++++" << std::endl;
		std::cout << e.what() << std::endl;
		std::cout << "==================================================" << std::endl;
	}

	/* std::cout << std::endl; */

	/* try{ */
	/* 	std::cout << std::endl; */ 
	/* 	std::cout << "++++++++++++ Constructor Excepts +++++++++++++++" << std::endl; */
	/* 	AForm a("B42-WgradeLow", 151, 150); */
	/* 	std::cout << std::endl; */
	/* } */
	/* catch (std::exception & e){ */
	/* 	std::cout << "++++++++++++++++++ WGradeLow ++++++++++++++++++" << std::endl; */
	/* 	std::cout << e.what() << std::endl; */
	/* 	std::cout << "==================================================" << std::endl; */
	/* } */

	/* std::cout << std::endl; */

	/* try{ */
	/* 	std::cout << std::endl; */ 
	/* 	std::cout << "++++++++++++ Construction Exceptions +++++++++++++" << std::endl; */
	/* 	AForm a("B42-XgradeHigh", 150, 0); */
	/* 	std::cout << std::endl; */
	/* } */
	/* catch (std::exception & e){ */
	/* 	std::cout << "++++++++++++++++++ XGradeHigh ++++++++++++++++++" << std::endl; */
	/* 	std::cout << e.what() << std::endl; */
	/* 	std::cout << "==================================================" << std::endl; */
	/* } */

	/* std::cout << std::endl; */

	/* try{ */
	/* 	std::cout << std::endl; */ 
	/* 	std::cout << "++++++++++++ Constructor Excepts +++++++++++++++" << std::endl; */
	/* 	AForm a("B42-XgradeLow", 150, 151); */
	/* 	std::cout << std::endl; */
	/* } */
	/* catch (std::exception & e){ */
	/* 	std::cout << "++++++++++++++++++ XGradeLow ++++++++++++++++++" << std::endl; */
	/* 	std::cout << e.what() << std::endl; */
		/* std::cout << "==================================================" << std::endl; */
	/* } */

	/* std::cout << std::endl; */

	/* try{ */
	/* 	std::cout << std::endl; */ 
	/* 	std::cout << "+++++++++++++++++ Constructor ++++++++++++++++++" << std::endl; */
	/* 	std::cout << "+++++++++++++++++++ Default ++++++++++++++++++++" << std::endl; */
	/* 	AForm a("A42-Default", 150, 150); */
	/* 	std::cout << "+++++++++++++++++++ Unsigned +++++++++++++++++++" << std::endl; */
	/* 	AForm b("A42-Unsigned", 10, 15, false); */
	/* 	std::cout << "++++++++++++++++++++ Signed ++++++++++++++++++++" << std::endl; */
	/* 	AForm c("A42-Signed", 10, 15, true); */
	/* 	std::cout << "================================================" << std::endl; */
	/* 	std::cout << std::endl; */
	/* 	std::cout << "+++ 24Copy Constructor And Assignation Overload +++" << std::endl; */
	/* 	AForm d(a); */
	/* 	std::cout << "=================================================" << std::endl; */
	/* 	std::cout << std::endl; */
	/* 	std::cout << "+++++++++++++++++ Operator Overload ++++++++++++++" << std::endl; */
	/* 	std::cout << d << std::endl; */
	/* 	std::cout << "==================================================" << std::endl; */
	/* 	std::cout << std::endl; */
	/* 	std::cout << "++++++++++++++++++++++ BeSigned +++++++++++++++++++" << std::endl; */
	/* 	std::cout << "+++++++++++++++++++++ Happy Path ++++++++++++++++++" << std::endl; */
	/* 	std::cout << *form << std::endl; */
	/* 	form->beSigned(alloc); */
	/* 	std::cout << *form << std::endl; */
	/* 	std::cout << "==================================================" << std::endl; */
	/* 	std::cout << std::endl; */
	/* 	std::cout << "+++++++++++++++++++ Already Signed +++++++++++++++" << std::endl; */
	/* 	std::cout << c << std::endl; */
	/* 	c.beSigned(alloc); */
	/* 	std::cout << c << std::endl; */
	/* 	std::cout << "==================================================" << std::endl; */
	/* 	std::cout << std::endl; */
	/* 	std::cout << "++++++++++++++++++++ Grade TooLow ++++++++++++++++" << std::endl; */
	/* 	std::cout << b << std::endl; */
	/* 	b.beSigned(alloc); */
	/* 	std::cout << b << std::endl; */
	/* 	std::cout << "==================================================" << std::endl; */
	/* 	std::cout << std::endl; */
	/* } */
	/* catch (std::exception & e){ */
	/* 	std::cout << e.what() << std::endl; */
	/* } */

	/* std::cout << std::endl; */

	/* try{ */ 
	/* 	std::cout << "+++++++++++++++++++ signForm +++++++++++++++++++++" << std::endl; */
	/* 	std::cout << "+++++++++++++++++ Constructor ++++++++++++++++++" << std::endl; */
	/* 	std::cout << "+++++++++++++++++++ Default ++++++++++++++++++++" << std::endl; */
	/* 	AForm d("C42-Default", 150, 150); */
	/* 	std::cout << "+++++++++++++++++++ Unsigned +++++++++++++++++++" << std::endl; */
	/* 	AForm e("C42-Unsigned", 10, 15, false); */
	/* 	std::cout << "++++++++++++++++++++ Signed ++++++++++++++++++++" << std::endl; */
	/* 	AForm f("C42-Signed", 10, 15, true); */
	/* 	std::cout << "================================================" << std::endl; */
	/* 	std::cout << std::endl; */
	/* 	std::cout << "+++++++++++++++++++++ Happy Path ++++++++++++++++++" << std::endl; */
	/* 	std::cout << d << std::endl; */
	/* 	alloc->signForm(d); */
	/* 	std::cout << d << std::endl; */
	/* 	std::cout << "==================================================" << std::endl; */
	/* 	std::cout << std::endl; */
	/* 	std::cout << "+++++++++++++++++++ Already Signed +++++++++++++++" << std::endl; */
	/* 	std::cout << f << std::endl; */
	/* 	alloc->signForm(f); */
	/* 	std::cout << f << std::endl; */
	/* 	std::cout << "==================================================" << std::endl; */
	/* 	std::cout << std::endl; */
	/* 	std::cout << "++++++++++++++++++++ Grade TooLow ++++++++++++++++" << std::endl; */
	/* 	std::cout << e << std::endl; */
	/* 	alloc->signForm(e); */
	/* 	std::cout << e << std::endl; */
	/* 	std::cout << "==================================================" << std::endl; */
	/* 	std::cout << std::endl; */
	/* } */
	/* catch (std::exception & e){ */
	/* 	std::cout << e.what() << std::endl; */
	/* } */

	/* std::cout << std::endl; */

	delete alloc;
	delete form;

	std::cout << "++++++++++++++++++ Leaks Summary +++++++++++++++++" << std::endl;
	std::cout << std::endl;
	system("leaks Bureaucracy");
	std::cout << "==================================================" << std::endl;
}
