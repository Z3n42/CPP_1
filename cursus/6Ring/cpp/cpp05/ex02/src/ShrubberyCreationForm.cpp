/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:55:42 by ingonzal          #+#    #+#             */
/*   Updated: 2023/05/04 11:57:11 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : _name("Basic ShrubberyCreationForm"), _Wgrade(147), _Xgrade(135), _sign(false){
	std::cout << *this << " Applied" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, int const Wgrade, int const Xgrade, bool sign) : _name(name), _Wgrade(Wgrade), _Xgrade(Xgrade), _sign(sign){
		setWgrade(Wgrade, this->getName());
		setXgrade(Xgrade, this->getName());
		std::cout << *this << " Applied" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : _name(src._name + " Photocopy"), _Wgrade(src.getWgrade()), _Xgrade(src.getXgrade()), _sign(src.getSign()){
	*this = src;
	std::cout << *this << " photocopied" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){
	std::cout << "+++++++++++++++++++ Destructor +++++++++++++++++++" << std::endl;
	std::cout << *this << " recicled" << std::endl;
	std::cout << "==================================================" << std::endl;
	std::cout << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs){
	if (this != &rhs){
		/* this->setName(rhs.getName()); */ // Const Name
		/* this->setGrade(rhs.getGrade(), rhs.getName()); */
		/* this->_name = rhs.getName(); */ // Const
		/* this->_Wgrade = rhs.getWgrade(); */ // Const
		/* this->_Xgrade = rhs.getXgrade(); */ // Const
		this->_sign = rhs.getSign();
		std::cout << *this << " Equalized to " << rhs << std::endl;
	}
	return(*this);
}

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & rhs){
	std::string sign;
	sign = " unsigned";
	if (rhs.getSign() == true)
		sign = " signed";
	o << rhs.getName() << " Form with " << rhs.getWgrade() << " Wgrade and " << rhs.getXgrade() << " Xgrade" << sign;
	return (o);
}

std::string const & ShrubberyCreationForm::getName(void) const{
	return (this->_name);
}


int const & ShrubberyCreationForm::getWgrade(void) const{
	return (this->_Wgrade);
}

int const & ShrubberyCreationForm::getXgrade(void) const{
	return (this->_Xgrade);
}

int const ShrubberyCreationForm::getSign(void) const{
	return (this->_sign);
}
// Const Name
/* void ShrubberyCreationForm::setName(std::string const &name){ */
/* 	this->_name = name; */
/* } */

void ShrubberyCreationForm::setWgrade(int const &Wlvl, std::string const &who = ""){
	if(Wlvl < 1)
		throw GradeTooHighException(" Wgrade too High", Wlvl, who);
	else if(Wlvl > 150)
		throw GradeTooLowException(" Wgrade too Low", Wlvl, who);
}

void ShrubberyCreationForm::setXgrade(int const &Xlvl, std::string const &who = ""){
	if(Xlvl < 1)
		throw GradeTooHighException(" Xgrade too High", Xlvl, who);
	else if(Xlvl > 150)
		throw GradeTooLowException(" Xgrade too Low", Xlvl, who);
}

void ShrubberyCreationForm::beSigned(Bureaucrat bureaucrat){
	if (this->_sign == false){
		if (this->_Wgrade >= bureaucrat.getGrade()){
			this->_sign = true;
			std::cout << bureaucrat.getName() << " signed " << *this << std::endl;
		}
		else
			std::cout << bureaucrat.getName() << " couldn’t sign " << *this << " because grade is too low" << std::endl;
			throw GradeTooLowException();
	}
	else
		std::cout << bureaucrat.getName() << " couldn’t sign " << *this << " because form already signed" << std::endl;
}

void ShrubberyCreationForm::beSigned(Bureaucrat *bureaucrat){
	if (bureaucrat){
		if (this->_sign == false){
			if (this->_Wgrade >= bureaucrat->getGrade()){
				this->_sign = true;
				std::cout << bureaucrat->getName() << " signed " << *this << std::endl;
			}
			else{
				std::cout << bureaucrat->getName() << " couldn’t sign " << *this << " because grade is too low" << std::endl;
				throw GradeTooLowException();
			}
		}
		else
			std::cout << bureaucrat->getName() << " couldn’t sign " << *this << " because form already signed" << std::endl;
	}
	else
		std::cout << "This bureucrat couldn’t sign " << *this << " because was already fired" << std::endl;
}

ShrubberyCreationForm::GradeTooHighException::GradeTooHighException(void){
   this->_HighError = " Grade is Higher than expected";
}

ShrubberyCreationForm::GradeTooHighException::GradeTooHighException(const char *error, int lvl, std::string const &name) : _HighError(error), _grade(lvl), _who(" for " + name){

}

int const & ShrubberyCreationForm::GradeTooHighException::getGrade(void) const{
	return (this->_grade);
}

std::string const & ShrubberyCreationForm::GradeTooHighException::getName(void) const{
	return (this->_who);
}

ShrubberyCreationForm::GradeTooHighException::~GradeTooHighException(void) throw(){

}

const char *ShrubberyCreationForm::GradeTooHighException::what(void) const throw(){
	return (this->_HighError);
}	



ShrubberyCreationForm::GradeTooLowException::GradeTooLowException(void){
	this->_LowError = " Grade is Lower than expected";
}

ShrubberyCreationForm::GradeTooLowException::GradeTooLowException(const char *error, int lvl, std::string const &name) : _LowError(error), _grade(lvl), _who(" for " + name){

}

int const & ShrubberyCreationForm::GradeTooLowException::getGrade(void) const{
	return (this->_grade);
}

std::string const & ShrubberyCreationForm::GradeTooLowException::getName(void) const{
	return (this->_who);
}

ShrubberyCreationForm::GradeTooLowException::~GradeTooLowException(void) throw(){

}

const char *ShrubberyCreationForm::GradeTooLowException::what(void) const throw(){
	return (this->_LowError);
}
