/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:51:24 by ingonzal          #+#    #+#             */
/*   Updated: 2023/04/23 21:07:27 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <sstream>

Bureaucrat::Bureaucrat(void) : _name("scholar"){
	setGrade(150, this->getName());
	std::cout << *this << " enroll" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
		setGrade(grade, this->getName());
		std::cout << *this << " enroll" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name + " Copia"){
	*this = src;
	std::cout << *this << " copied" << std::endl;
}

Bureaucrat::~Bureaucrat(void){
	std::cout << "+++++++++++++++++++ Destructor +++++++++++++++++++" << std::endl;
	std::cout << *this << " fired" << std::endl;
	std::cout << "==================================================" << std::endl;
	std::cout << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs){
	if (this != &rhs){
		/* this->setName(rhs.getName()); */ // Const Name
		this->setGrade(rhs.getGrade(), rhs.getName());
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

// Const Name
/* void Bureaucrat::setName(std::string const &name){ */
/* 	this->_name = name; */
/* } */

void Bureaucrat::setGrade(int const &lvl, std::string const &who = ""){
	if(lvl < 1)
		throw GradeTooHighException(" Grade too High", lvl, who);
	else if(lvl > 150)
		throw GradeTooLowException(" Grade too Low", lvl, who);
	else
		this->_grade = lvl;
}

void Bureaucrat::GradeUp(void){
	if ((this->_grade - 1) < 1)
		throw GradeTooHighException(" Grade too High", 0, this->_name);
	setGrade(--this->_grade);
}

void Bureaucrat::GradeDown(void){
	if ((this->_grade + 1) > 150)
		throw GradeTooLowException(" Grade too Low", 151, this->_name);
	setGrade(++this->_grade);
}



Bureaucrat::GradeTooHighException::GradeTooHighException(void){
   this->_HighError = " Grade is Higher than expected";
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const char *error, int lvl, std::string const &name) : _HighError(error), _grade(lvl), _who(" for " + name){

}

int const & Bureaucrat::GradeTooHighException::getGrade(void) const{
	return (this->_grade);
}

std::string const & Bureaucrat::GradeTooHighException::getName(void) const{
	return (this->_who);
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw(){

}

const char *Bureaucrat::GradeTooHighException::what(void) const throw(){
	return (this->_HighError);
}	



Bureaucrat::GradeTooLowException::GradeTooLowException(void){
	this->_LowError = " Grade is Lower than expected";
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const char *error, int lvl, std::string const &name) : _LowError(error), _grade(lvl), _who(" for " + name){

}

int const & Bureaucrat::GradeTooLowException::getGrade(void) const{
	return (this->_grade);
}

std::string const & Bureaucrat::GradeTooLowException::getName(void) const{
	return (this->_who);
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw(){

}

const char *Bureaucrat::GradeTooLowException::what(void) const throw(){
	return (this->_LowError);
}

/* All no-way tryouts */

/* void Bureaucrat::setGrade(int const &lvl, std::string const &who = ""){ */
/* 	std::cout << "SET IN LVL =>" << lvl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl; */
/* 	try{ */
/* 	std::stringstream stream; */
/* 	std::string msg; */
/* 	std::string c; */
/* 	stream << lvl; */
/* 	stream >> c; */
/* 	msg = c + " Grade is too High"; */
/* 	if(lvl < 1){ */
		/* std::cout << typeid(c).name() << std::endl; */
/* 		throw GradeTooHighException(" Grade too High", lvl, who); */
/* 		throw GradeTooHighException(static_cast<char*>(&msg[0])); */
/* 	} */
/* 	else if(lvl > 150){ */
/* 		std::stringstream stream; */
/* 		std::string msg; */
/* 		std::string c; */
/* 		stream << lvl; */
/* 		stream >> c; */
/* 		msg = c + " Grade is too low"; */
/* 		throw GradeTooLowException(" Grade too Low", lvl, who); */
/* 		throw GradeTooLowException(static_cast<char*>(&msg[0])); */
/* 	} */
/* 	else{ */
/* 		this->_grade = lvl; */
/* 	} */
/* 		} */
/* 	catch (std::exception & e){ */
/* 		std::cout << lvl << e.what() << std::endl; */
/* 	} */
/* } */
