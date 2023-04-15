/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:51:24 by ingonzal          #+#    #+#             */
/*   Updated: 2023/04/15 19:49:46 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("scholar"){
	setGrade(150);
	std::cout << *this << " enroll" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
		setGrade(grade);
		std::cout << *this << " enroll" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name){
	*this = src;
	std::cout << *this << " copied" << std::endl;
}

Bureaucrat::~Bureaucrat(void){
	std::cout << *this << " fired" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs){
	if (this != &rhs){
		/* this->setName(rhs.getName()); */
		this->setGrade(rhs.getGrade());
		std::cout << *this << " Equalized to " << rhs << std::endl;
	}
	return(*this);
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs){
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (o);
}

std::string const & Bureaucrat::getName(void) const{
	return (this->_name);
}


int const & Bureaucrat::getGrade(void) const{
	return (this->_grade);
}

/* void Bureaucrat::setName(std::string const &name){ */
/* 	this->_name = name; */
/* } */

void Bureaucrat::setGrade(int const &lvl){
	try{
		if(lvl < 1)
			throw GradeTooHighException(" Grade is Too High");
		else if(lvl > 150)
			throw GradeTooLowException(" Grade is Too Low");
		else
			this->_grade = lvl;
		}
	catch (std::exception & e){
		std::cout << lvl << e.what() << std::endl;
	}
}

void Bureaucrat::GradeUp(void){
	setGrade(this->_grade += 1);
}

void Bureaucrat::GradeDown(void){
	setGrade(this->_grade -= 1);
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const char *error) : _HighError(error){

}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw(){

}

const char *Bureaucrat::GradeTooHighException::what(void) const throw(){
	return (this->_HighError);
}	

Bureaucrat::GradeTooLowException::GradeTooLowException(const char *error) : _LowError(error){

}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw(){

}

const char *Bureaucrat::GradeTooLowException::what(void) const throw(){
	return (this->_LowError);
}	
