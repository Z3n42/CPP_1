/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:55:14 by ingonzal          #+#    #+#             */
/*   Updated: 2023/04/30 20:24:41 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("Basic Form"), _Wgrade(150), _Xgrade(150), _sign(false){
	/* setGrade(150, this->getName()); */
	std::cout << *this << " Applied" << std::endl;
}

Form::Form(std::string name, int const Wgrade, int const Xgrade, bool sign = false) : _name(name), _Wgrade(Wgrade), _Xgrade(Xgrade), _sign(sign){
		setWgrade(Wgrade, this->getName());
		setXgrade(Xgrade, this->getName());
		std::cout << *this << " Applied" << std::endl;
}

Form::Form(Form const & src) : _name(src._name + " Photocopy"), _Wgrade(src.getWgrade()), _Xgrade(src.getXgrade()), _sign(src.getSign()){
	*this = src;
	std::cout << *this << " photocopied" << std::endl;
}

Form::~Form(void){
	std::cout << "+++++++++++++++++++ Destructor +++++++++++++++++++" << std::endl;
	std::cout << *this << " recicled" << std::endl;
	std::cout << "==================================================" << std::endl;
	std::cout << std::endl;
}

Form & Form::operator=(Form const & rhs){
	if (this != &rhs){
		/* this->setName(rhs.getName()); */ // Const Name
		/* this->setGrade(rhs.getGrade(), rhs.getName()); */
		/* this->_name = rhs.getName(); */
		/* this->_Wgrade = rhs.getWgrade(); */
		/* this->_Xgrade = rhs.getXgrade(); */
		this->_sign = rhs.getSign();
		std::cout << *this << " Equalized to " << rhs << std::endl;
	}
	return(*this);
}

std::ostream & operator<<(std::ostream & o, Form const & rhs){
	std::string sign;
	if (rhs.getSign() == false)
		sign = " unsigned";
	else
		sign = " signed";
	o << rhs.getName() << "Form with Wgrade " << rhs.getWgrade() << " and Xgrade " << rhs.getWgrade() << sign;
	return (o);
}

std::string const & Form::getName(void) const{
	return (this->_name);
}


int const & Form::getWgrade(void) const{
	return (this->_Wgrade);
}

int const & Form::getXgrade(void) const{
	return (this->_Xgrade);
}

int const Form::getSign(void) const{
	return (this->_sign);
}
// Const Name
/* void Form::setName(std::string const &name){ */
/* 	this->_name = name; */
/* } */

void Form::setWgrade(int const &Wlvl, std::string const &who = ""){
	if(Wlvl < 1)
		throw GradeTooHighException(" Wgrade too High", Wlvl, who);
	else if(Wlvl > 150)
		throw GradeTooLowException(" Wgrade too Low", Wlvl, who);
}

void Form::setXgrade(int const &Xlvl, std::string const &who = ""){
	if(Xlvl < 1)
		throw GradeTooHighException(" Xgrade too High", Xlvl, who);
	else if(Xlvl > 150)
		throw GradeTooLowException(" Xgrade too Low", Xlvl, who);
}

void Form::beSigned(Bureaucrat bureaucrat){
	if (this->_Wgrade <= bureaucrat.getGrade()){
		this->_sign = true;
		std::cout << bureaucrat.getName() << " signed " << *this;
	}
	else{
		std::cout << bureaucrat.getName() << " couldn’t sign " << *this << " because";
		throw GradeTooLowException();
	}
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
