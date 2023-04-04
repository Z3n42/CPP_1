/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:51:24 by ingonzal          #+#    #+#             */
/*   Updated: 2023/04/04 21:23:04 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("NoName"), _grade(0){
	try{
		if (this->_grade != 0)
			throw "Instantiation is not possible";
		std::cout << *this << " Instantiated" << std::endl;
	}
	catch (std::exception & e){
		std::cout << e << std::endl;
	}
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
	std::cout << *this << " Instantiated" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src){
	*this = src;
	std::cout << *this << " Copied" << std::endl;
}

Bureaucrat::~Bureaucrat(void){
	std::cout << *this << " Instantiated" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs){
	if (this != &rhs){
		std::cout << *this << " Equalized to " << rh/s << std::endl;
		this->_name = rhs._name;
		this->_grade = rhs._grade;
	}
	return(*this);
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs){
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (o);
}

