/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:40:27 by ingonzal          #+#    #+#             */
/*   Updated: 2023/05/08 20:18:41 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void){
}

Intern::Intern(Intern const &src){

	*this = src;	
}

Intern& Intern::operator=(Intern const &intern){

	return (*this);
}

Intern::~Intern(void){
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	AForm *form[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i;

	i = 0;
	while (i < 3 && forms[i] != formName){
		i++;	
	}
	return form[i]; 
}
