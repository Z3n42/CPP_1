/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:55:14 by ingonzal          #+#    #+#             */
/*   Updated: 2023/04/26 19:58:24 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("scholar"){
	setGrade(150, this->getName());
	std::cout << *this << " enroll" << std::endl;
}

Form::Form(std::string name, int grade) : _name(name){
		setGrade(grade, this->getName());
		std::cout << *this << " enroll" << std::endl;
}

Form::Form(Form const & src) : _name(src._name + " Copia"){
	*this = src;
	std::cout << *this << " copied" << std::endl;
}

Form::~Form(void){
	std::cout << "+++++++++++++++++++ Destructor +++++++++++++++++++" << std::endl;
	std::cout << *this << " fired" << std::endl;
	std::cout << "==================================================" << std::endl;
	std::cout << std::endl;
}

Form & Form::operator=(Form const & rhs){
	if (this != &rhs){
		/* this->setName(rhs.getName()); */ // Const Name
		this->setGrade(rhs.getGrade(), rhs.getName());
		std::cout << *this << " Equalized to " << rhs << std::endl;
	}
	return(*this);
}

std::ostream & operator<<(std::ostream & o, Form const & rhs){
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (o);
}

std::string const & Form::getName(void) const{
	return (this->_name);
}


int const & Form::getGrade(void) const{
	return (this->_grade);
}

// Const Name
/* void Form::setName(std::string const &name){ */
/* 	this->_name = name; */
/* } */

void Form::setGrade(int const &lvl, std::string const &who = ""){
	if(lvl < 1)
		throw GradeTooHighException(" Grade too High", lvl, who);
	else if(lvl > 150)
		throw GradeTooLowException(" Grade too Low", lvl, who);
	else
		this->_grade = lvl;
}

void Form::GradeUp(void){
	if ((this->_grade - 1) < 1)
		throw GradeTooHighException(" Grade too High", 0, this->_name);
	setGrade(--this->_grade);
}

void Form::GradeDown(void){
	if ((this->_grade + 1) > 150)
		throw GradeTooLowException(" Grade too Low", 151, this->_name);
	setGrade(++this->_grade);
}



Form::GradeTooHighException::GradeTooHighException(void){
   this->_HighError = " Grade is Higher than expected";
}

Form::GradeTooHighException::GradeTooHighException(const char *error, int lvl, std::string const &name) : _HighError(error), _grade(lvl), _who(" for " + name){

}

int const & Form::GradeTooHighException::getGrade(void) const{
	return (this->_grade);
}

std::string const & Form::GradeTooHighException::getName(void) const{
	return (this->_who);
}

Form::GradeTooHighException::~GradeTooHighException(void) throw(){

}

const char *Form::GradeTooHighException::what(void) const throw(){
	return (this->_HighError);
}	



Form::GradeTooLowException::GradeTooLowException(void){
	this->_LowError = " Grade is Lower than expected";
}

Form::GradeTooLowException::GradeTooLowException(const char *error, int lvl, std::string const &name) : _LowError(error), _grade(lvl), _who(" for " + name){

}

int const & Form::GradeTooLowException::getGrade(void) const{
	return (this->_grade);
}

std::string const & Form::GradeTooLowException::getName(void) const{
	return (this->_who);
}

Form::GradeTooLowException::~GradeTooLowException(void) throw(){

}

const char *Form::GradeTooLowException::what(void) const throw(){
	return (this->_LowError);
}
