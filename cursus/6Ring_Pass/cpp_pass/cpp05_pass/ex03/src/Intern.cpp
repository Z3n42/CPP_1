/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:40:27 by ingonzal          #+#    #+#             */
/*   Updated: 2023/05/13 17:24:19 by ingonzal         ###   ########.fr       */
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
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 3){
		if (forms[i] == formName){
			j = i;
			break;
		}
		i++;
	}
	if (i == 3 && j == 0)
		throw Exception();

	AForm *form[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};

	i = 0;
	j = 0;
	while (i < 3){
		if (forms[i] == formName)
			j = i;
		else
			delete form[i];
		i++;
	}
	return form[j]; 
}

const char* Intern::Exception::what() const throw()
{
	return ("ERROR: Unknown Form");
}
