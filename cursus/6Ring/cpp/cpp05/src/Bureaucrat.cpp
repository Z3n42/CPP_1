/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:51:24 by ingonzal          #+#    #+#             */
/*   Updated: 2023/04/08 20:06:33 by ingonzal         ###   ########.fr       */
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
		/* std::cout << e << std::endl; */
	}
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
	if(grade < 0)
		throw Bureaucrat::GradeTooHigException(" too high");
	else if(grade > 150)
		throw Bureaucrat::GradeTooLowException(" too low");
	else
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
		this->_name = rhs._name;
		this->_grade = rhs._grade;
		std::cout << *this << " Equalized to " << rhs << std::endl;
	}
	return(*this);
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs){
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (o);
}

std::string Bureaucrat::getName(void) const{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const{
	return (this->_grade);
}

void Bureaucrat::setGradeUp(void){
	this->_grade += 1;
}

void Bureaucrat::setGradeDown(void){
	this->_grade -= 1;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string Error) : _HighError(Error){

}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw(){

}

Bureaucrat::GradeTooHighException::what() const throw(){
	std::cout << *this << this->_HighError << std::endl;
}	

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string Error) : _LowError(Error){

}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw(){

}

Bureaucrat::GradeTooLowException::what() const throw(){
	std::cout << *this << this->_LowError << std::endl;
}	
