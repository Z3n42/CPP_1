/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:55:42 by ingonzal          #+#    #+#             */
/*   Updated: 2023/05/07 21:09:41 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) :  AForm("Basic ShrubberyCreationForm", 145, 137, false), _target("Basic target"){
	std::cout << *this << " Applied" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShubberryForm", 145, 137, false), _target(target){
		std::cout << *this << " Applied" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src.getName() + " Photocopy", src.getWgrade(), src.getXgrade(), src.getSign()), _target(src.getTarget()){
	/* if you are going to use const members workarround comment assignation: */
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
		/* this->setName(rhs.getName()); // Const Name */
		/* this->setGrade(rhs.getGrade(), rhs.getName()); */
		/* this->_name = rhs.getName(); // Const */
		/* this->_Wgrade = rhs.getWgrade(); // Const */
		/* this->_Xgrade = rhs.getXgrade(); // Const */
		/* this->_sign = rhs.getSign(); */
		this->_target = rhs.getTarget();
		std::cout << *this << " Equalized to:\n" << rhs << std::endl;
/* =============================================================================================== */
		//Workarround to avoid natural behaviour about const members and assignation:
		//Problem: Original pointer substitution
		/* this->~ShrubberyCreationForm(); */
		/* new (this) ShrubberyCreationForm(rhs); */
	}
	return(*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (checkSign()){
		if (executor.getGrade() <= this->getXgrade()){
			std::ofstream file(this->_target + "_shrubbery");
			std::string const tree = 
			"	  \e[1;33m*42*\e[0m\e[1;32m\n"
			"	   /.\\\n"
			"	  /\e[0m\e[1;31mo\e[0m\e[1;32m..\\\n"
			"	  /..\e[0m\e[1;36mo\e[0m\e[1;32m\\\n"
			"	 /.\e[0m\e[1;35mo\e[0m\e[1;32m..\e[0m\e[1;31mo\e[0m\e[1;32m\\\n"
			"	 /...\e[0m\e[1;36mo\e[0m\e[1;32m.\\\n"
			"	/..\e[0m\e[1;35mo\e[0m\e[1;32m....\\\n"
			"	^^^[_]^^^ \n";
			file << tree;
		}
		else
			throw AForm::GradeTooLowException("Execution Grade is lower than expected", executor.getGrade(), executor.getName());
	}
	else
	std::cout << executor.getName() << " couldn’t execute " << *this << " because form not signed" << std::endl;
}

std::string const & ShrubberyCreationForm::getTarget(void) const{
	return (this->_target);
}

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & rhs){
	std::string sign;
	sign = " unsigned";
	if (rhs.getSign() == true)
		sign = " signed";
	o << rhs.getName() << " Form with " << rhs.getWgrade() << " Wgrade and " << rhs.getXgrade() << " Xgrade" << sign << " targeted to " << rhs.getTarget();
	return (o);
}
