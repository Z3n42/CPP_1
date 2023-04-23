/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:39:24 by ingonzal          #+#    #+#             */
/*   Updated: 2023/04/23 19:09:41 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <stdlib.h>

int main(void) {
	Bureaucrat *alloc = NULL;
	Bureaucrat *OverAlloc = NULL;
	Bureaucrat *UnderAlloc = NULL;
	try{
		std::cout << std::endl; 
		std::cout << "+++++++++++++++++ Constructor ++++++++++++++++++" << std::endl;
		Bureaucrat a("pepe", 23);
		std::cout << "================================================" << std::endl;
		std::cout << std::endl;
		std::cout << "+++ Copy Constructor And Assignation Overload +++" << std::endl;
		Bureaucrat f(a);
		std::cout << "=================================================" << std::endl;
		std::cout << std::endl;
		std::cout << "+++++++++++++++++ Operator Overload ++++++++++++++" << std::endl;
		std::cout << f << std::endl;
		std::cout << "==================================================" << std::endl;
		std::cout << std::endl;
		std::cout << "++++++++++++++++++++++ UpGrade +++++++++++++++++++" << std::endl;
		f.GradeUp();
		std::cout << f << std::endl;
		std::cout << "==================================================" << std::endl;
		std::cout << std::endl;
		std::cout << "+++++++++++++++++++++ DownGrade ++++++++++++++++++" << std::endl;
		f.GradeDown();
		std::cout << f << std::endl;
		std::cout << "==================================================" << std::endl;
		std::cout << std::endl;
		std::cout << "++++++++++++++++ Common Exceptions +++++++++++++++" << std::endl;
		std::cout << "--------------------------------------------------" << std::endl;
		std::cout << std::endl;
		Bureaucrat b("paco", 1);
		std::cout << "+++++++++++++++++++++ DownGrade ++++++++++++++++++" << std::endl;
		b.GradeUp();
		std::cout << b << "<<<<<<<<<<<<<<<<" << std::endl;
		std::cout << "==================================================" << std::endl;
		alloc = new Bureaucrat ("pupu", 222);
		Bureaucrat e("pipo", 19);
	}
	catch (Bureaucrat::GradeTooHighException & e){
		std::cout << "+++++++++++++++++ TooHigh Exception +++++++++++++++" << std::endl;
		std::cout << e.getGrade() <<  e.what() << e.getName() << std::endl;
		std::cout << "==================================================" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException & e){
		std::cout << "+++++++++++++++++ TooLow Exception +++++++++++++++" << std::endl;
		std::cout << e.getGrade() << e.what() << e.getName() << std::endl;
		std::cout << "==================================================" << std::endl;
	}
	std::cout << std::endl;
	try{
		Bureaucrat b("patxi", 0);
	}
	catch (Bureaucrat::GradeTooHighException & e){
		std::cout << "+++++++++++++++++ TooHigh Exception +++++++++++++++" << std::endl;
		std::cout << e.getGrade() <<  e.what() << e.getName() << std::endl;
		std::cout << "==================================================" << std::endl;
	}
	std::cout << std::endl;
	try{
		Bureaucrat b("pascu", -1);
	}
	catch (Bureaucrat::GradeTooHighException & e){
		std::cout << "+++++++++++++++++ TooHigh Exception +++++++++++++++" << std::endl;
		std::cout << e.getGrade() <<  e.what() << e.getName() << std::endl;
		std::cout << "==================================================" << std::endl;
	}
	std::cout << std::endl;
	try{
		Bureaucrat b("pescu", -1);
	}
	catch (std::exception & e){
		std::cout << "++++++++++++ General TooHigh Exception +++++++++++" << std::endl;
		std::cout << e.what() << std::endl;
		std::cout << "==================================================" << std::endl;
	}
	std::cout << std::endl;
	try{
		Bureaucrat b("pintxo", 151);
	}
	catch (std::exception & e){
		std::cout << "++++++++++++ General TooLow Exception +++++++++++" << std::endl;
		std::cout << e.what() << std::endl;
		std::cout << "==================================================" << std::endl;
	}
	/* /1* try{ *1/ */
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
