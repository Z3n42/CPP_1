/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:42:17 by ingonzal          #+#    #+#             */
/*   Updated: 2023/05/07 21:18:19 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("Basic Form"), _Wgrade(150), _Xgrade(150), _sign(false){
	std::cout << *this << " Applied" << std::endl;
}

AForm::AForm(std::string name, int const Wgrade, int const Xgrade, bool sign) : _name(name), _Wgrade(Wgrade), _Xgrade(Xgrade), _sign(sign){
		setWgrade(Wgrade, this->getName());
		setXgrade(Xgrade, this->getName());
		std::cout << *this << " Applied" << std::endl;
}

AForm::AForm(AForm const & src) : _name(src._name + " Photocopy"), _Wgrade(src.getWgrade()), _Xgrade(src.getXgrade()), _sign(src.getSign()){
	*this = src;
	std::cout << *this << " photocopied" << std::endl;
}

AForm::~AForm(void){
	std::cout << "+++++++++++++++++++ Destructor +++++++++++++++++++" << std::endl;
	std::cout << *this << " recicled" << std::endl;
	std::cout << "==================================================" << std::endl;
	std::cout << std::endl;
}

AForm & AForm::operator=(AForm const & rhs){
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

std::ostream & operator<<(std::ostream & o, AForm const & rhs){
	std::string sign;
	sign = " unsigned";
	if (rhs.getSign() == true)
		sign = " signed";
	o << rhs.getName() << " Form with " << rhs.getWgrade() << " Wgrade and " << rhs.getXgrade() << " Xgrade" << sign;
	return (o);
}

std::string const & AForm::getName(void) const{
	return (this->_name);
}


int const & AForm::getWgrade(void) const{
	return (this->_Wgrade);
}

int const & AForm::getXgrade(void) const{
	return (this->_Xgrade);
}

int const AForm::getSign(void) const{
	return (this->_sign);
}
// Const Name
/* void AForm::setName(std::string const &name){ */
/* 	this->_name = name; */
/* } */

void AForm::setWgrade(int const &Wlvl, std::string const &who = ""){
	if(Wlvl < 1)
		throw GradeTooHighException(" Wgrade too High", Wlvl, who);
	else if(Wlvl > 150)
		throw GradeTooLowException(" Wgrade too Low", Wlvl, who);
}

void AForm::setXgrade(int const &Xlvl, std::string const &who = ""){
	if(Xlvl < 1)
		throw GradeTooHighException(" Xgrade too High", Xlvl, who);
	else if(Xlvl > 150)
		throw GradeTooLowException(" Xgrade too Low", Xlvl, who);
}

int AForm::checkSign() const{
	if (this->_sign == true)
		return (1);
	return (0);
}

void AForm::beSigned(Bureaucrat bureaucrat){
	if (!checkSign()){
		if (this->_Wgrade >= bureaucrat.getGrade()){
			this->_sign = true;
			std::cout << bureaucrat.getName() << " signed " << *this << std::endl;
		}
		else
			std::cout << bureaucrat.getName() << " couldn’t sign " << *this << " because signing grade is too low" << std::endl;
			throw AForm::GradeTooLowException("Signing Grade is lower than expected", bureaucrat.getGrade(), bureaucrat.getName());
	}
	else
		std::cout << bureaucrat.getName() << " couldn’t sign " << *this << " because form already signed" << std::endl;
}

void AForm::beSigned(Bureaucrat *bureaucrat){
	if (bureaucrat){
		if (this->_sign == false){
			if (this->_Wgrade >= bureaucrat->getGrade()){
				this->_sign = true;
				std::cout << bureaucrat->getName() << " signed " << *this << std::endl;
			}
			else{
				std::cout << bureaucrat->getName() << " couldn’t sign " << *this << " because signing grade is too low" << std::endl;
				throw AForm::GradeTooLowException("Signing Grade is lower than expected", bureaucrat->getGrade(), bureaucrat->getName());
			}
		}
		else
			std::cout << bureaucrat->getName() << " couldn’t sign " << *this << " because form already signed" << std::endl;
	}
	else
		std::cout << "This bureucrat couldn’t sign " << *this << " because was already fired" << std::endl;
}

AForm::GradeTooHighException::GradeTooHighException(void){
   this->_HighError = " Grade is Higher than expected";
}

AForm::GradeTooHighException::GradeTooHighException(const char *error, int lvl, std::string const &name) : _HighError(error), _grade(lvl), _who(" for " + name){

}

int const & AForm::GradeTooHighException::getGrade(void) const{
	return (this->_grade);
}

std::string const & AForm::GradeTooHighException::getName(void) const{
	return (this->_who);
}

AForm::GradeTooHighException::~GradeTooHighException(void) throw(){

}

const char *AForm::GradeTooHighException::what(void) const throw(){
	return (this->_HighError);
}	



AForm::GradeTooLowException::GradeTooLowException(void){
	this->_LowError = " Grade is Lower than expected";
}

AForm::GradeTooLowException::GradeTooLowException(const char *error, int lvl, std::string const &name) : _LowError(error), _grade(lvl), _who(" for " + name){

}

int const & AForm::GradeTooLowException::getGrade(void) const{
	return (this->_grade);
}

std::string const & AForm::GradeTooLowException::getName(void) const{
	return (this->_who);
}

AForm::GradeTooLowException::~GradeTooLowException(void) throw(){

}

const char *AForm::GradeTooLowException::what(void) const throw(){
	return (this->_LowError);
}
