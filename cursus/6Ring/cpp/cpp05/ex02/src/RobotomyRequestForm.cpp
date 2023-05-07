/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:08:34 by ingonzal          #+#    #+#             */
/*   Updated: 2023/05/07 21:06:36 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <unistd.h>
#include <time.h>

RobotomyRequestForm::RobotomyRequestForm(void) :  AForm("Basic RobotomyRequestForm", 72, 45, false), _target("Basic target"){
	std::cout << *this << " Applied" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyForm", 72, 45, false), _target(target){
		std::cout << *this << " Applied" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src.getName() + " Photocopy", src.getWgrade(), src.getXgrade(), src.getSign()), _target(src.getTarget()){
	/* if you are going to use const members workarround comment assignation: */
	*this = src;
	std::cout << *this << " photocopied" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void){
	std::cout << "+++++++++++++++++++ Destructor +++++++++++++++++++" << std::endl;
	std::cout << *this << " recicled" << std::endl;
	std::cout << "==================================================" << std::endl;
	std::cout << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs){
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
		/* this->~RobotomyRequestForm(); */
		/* new (this) RobotomyRequestForm(rhs); */
	}
	return(*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	if (checkSign()){
		if (executor.getGrade() <= this->getXgrade()){
			std::cout << std::endl; 
			std::cout << " BZZ BzZZZZZzzz bZZzzZZ" << std::endl;
			int level;
			srand (time(NULL));
			level = rand () % 10 + 1;
			if (level % 2 == 0)
				std::cout << this->_target << " has been robotomized" << std::endl;
			else
				std::cout << "Robotomy to " << this->_target << " FAILED!!!" << std::endl;
		}
		else
			throw AForm::GradeTooLowException("Execution Grade is lower than expected", executor.getGrade(), executor.getName());
	}
	else
	std::cout << executor.getName() << " couldn’t execute " << *this << " because form not signed" << std::endl;
}

std::string const & RobotomyRequestForm::getTarget(void) const{
	return (this->_target);
}

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & rhs){
	std::string sign;
	sign = " unsigned";
	if (rhs.getSign() == true)
		sign = " signed";
	o << rhs.getName() << " Form with " << rhs.getWgrade() << " Wgrade and " << rhs.getXgrade() << " Xgrade" << sign << " targeted to " << rhs.getTarget();
	return (o);
}
