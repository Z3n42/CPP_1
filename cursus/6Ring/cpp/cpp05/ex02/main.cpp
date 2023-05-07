/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:39:24 by ingonzal          #+#    #+#             */
/*   Updated: 2023/05/07 21:04:41 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
	Bureaucrat *SH_alloc = NULL;
	Bureaucrat *SH_signer = NULL;
	Bureaucrat *SH_unsigner = NULL;
	ShrubberyCreationForm *SH_form = NULL;
	Bureaucrat *RO_alloc = NULL;
	Bureaucrat *RO_signer = NULL;
	Bureaucrat *RO_unsigner = NULL;
	RobotomyRequestForm *RO_form = NULL;
	Bureaucrat *PR_alloc = NULL;
	Bureaucrat *PR_signer = NULL;
	Bureaucrat *PR_unsigner = NULL;
	PresidentialPardonForm *PR_form = NULL;

	try{ 
		std::cout << "+++++++++++++++++++ ShrubberyCreationForm Allocated ++++++++++++++++++++" << std::endl;
		SH_alloc = new Bureaucrat("SH_Alloc", 137);
		SH_signer = new Bureaucrat("SH_Signer", 145);
		SH_unsigner = new Bureaucrat("SH_UnSigner", 150);
		SH_form = new ShrubberyCreationForm ("SH_Scrooge");
		std::cout << "==================================================" << std::endl;
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try{
		std::cout << std::endl; 
		std::cout << "++++++++++++ ShrubberyCreationForm sign Excepts +++++++++++++++" << std::endl;
		SH_unsigner->signForm(*SH_form);
		SH_form->execute(*SH_alloc);
		std::cout << std::endl;
	}
	catch (std::exception & e){
		std::cout << "++++++++++++++++++ WGradeHigh ++++++++++++++++++" << std::endl;
		std::cout << e.what() << std::endl;
		std::cout << "==================================================" << std::endl;
	}

	std::cout << std::endl;

	try{
		std::cout << std::endl; 
		std::cout << "++++++++++++ ShrubberyCreationForm Execution Excepts +++++++++++++++" << std::endl;
		SH_signer->signForm(*SH_form);
		SH_form->execute(*SH_unsigner);
		std::cout << std::endl;
	}
	catch (std::exception & e){
		std::cout << "++++++++++++++++++ WGradeHigh ++++++++++++++++++" << std::endl;
		std::cout << e.what() << std::endl;
		std::cout << "==================================================" << std::endl;
	}

	std::cout << std::endl;

	try{
		std::cout << std::endl; 
		std::cout << "++++++++++++ ShrubberyCreationForm Already signed +++++++++++++++" << std::endl;
		SH_signer->signForm(*SH_form);
		SH_form->execute(*SH_unsigner);
		std::cout << std::endl;
	}
	catch (std::exception & e){
		std::cout << "++++++++++++++++++ WGradeHigh ++++++++++++++++++" << std::endl;
		std::cout << e.what() << std::endl;
		std::cout << "==================================================" << std::endl;
	}

	std::cout << std::endl;

	try{
		std::cout << std::endl; 
		std::cout << "++++++++++++ ShrubberyCreationForm HappyPath +++++++++++++++" << std::endl;
		ShrubberyCreationForm SH_A42("42");
		SH_signer->signForm(SH_A42);
		SH_A42.execute(*SH_alloc);
		std::cout << std::endl;
	}
	catch (std::exception & e){
		std::cout << "++++++++++++++++++ WGradeHigh ++++++++++++++++++" << std::endl;
		std::cout << e.what() << std::endl;
		std::cout << "==================================================" << std::endl;
	}

	std::cout << std::endl;
	try{
		std::cout << std::endl; 
		std::cout << "++++++++++++ ShrubberyCreationForm Constructors +++++++++++++++" << std::endl;
		ShrubberyCreationForm a("people");
		ShrubberyCreationForm b("42");
		ShrubberyCreationForm c(a);
		std::cout << "+++ SH_Copy Constructor And Assignation Overload +++" << std::endl;
		c = b;
		std::cout << "+++++++++++++++++ SH_Operator Overload ++++++++++++++" << std::endl;
		std::cout << c << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception & e){
		std::cout << "++++++++++++++++++ WGradeLow ++++++++++++++++++" << std::endl;
		std::cout << e.what() << std::endl;
		std::cout << "==================================================" << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	try{ 
		std::cout << "+++++++++++++++++++ RobotomyRequestForm Allocated ++++++++++++++++++++" << std::endl;
		RO_alloc = new Bureaucrat("RO_Alloc", 45);
		RO_signer = new Bureaucrat("RO_Signer", 72);

		RO_unsigner = new Bureaucrat("RO_UnSigner", 150);
		RO_form = new RobotomyRequestForm ("RO_Scrooge");
		std::cout << "==================================================" << std::endl;
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try{
		std::cout << std::endl; 
		std::cout << "++++++++++++ RobotomyRequestForm sign Excepts +++++++++++++++" << std::endl;
		RO_unsigner->signForm(*RO_form);
		RO_form->execute(*RO_alloc);
		std::cout << std::endl;
	}
	catch (std::exception & e){
		std::cout << "++++++++++++++++++ WGradeHigh ++++++++++++++++++" << std::endl;
		std::cout << e.what() << std::endl;
		std::cout << "==================================================" << std::endl;
	}

	std::cout << std::endl;

	try{
		std::cout << std::endl; 
		std::cout << "++++++++++++ RobotomyRequestForm Execution Excepts +++++++++++++++" << std::endl;
		RO_signer->signForm(*RO_form);
		RO_form->execute(*RO_unsigner);
		std::cout << std::endl;
	}
	catch (std::exception & e){
		std::cout << "++++++++++++++++++ WGradeHigh ++++++++++++++++++" << std::endl;
		std::cout << e.what() << std::endl;
		std::cout << "==================================================" << std::endl;
	}

	std::cout << std::endl;

	try{
		std::cout << std::endl; 
		std::cout << "++++++++++++ RobotomyRequestForm Already signed +++++++++++++++" << std::endl;
		RO_signer->signForm(*RO_form);
		RO_form->execute(*RO_unsigner);
		std::cout << std::endl;
	}
	catch (std::exception & e){
		std::cout << "++++++++++++++++++ WGradeHigh ++++++++++++++++++" << std::endl;
		std::cout << e.what() << std::endl;
		std::cout << "==================================================" << std::endl;
	}

	std::cout << std::endl;

	try{
		std::cout << std::endl; 
		std::cout << "++++++++++++ RobotomyRequestForm HappyPath +++++++++++++++" << std::endl;
		RobotomyRequestForm RO_A42("42");
		RO_signer->signForm(RO_A42);
		RO_A42.execute(*RO_alloc);
		std::cout << std::endl;
	}
	catch (std::exception & e){
		std::cout << "++++++++++++++++++ WGradeHigh ++++++++++++++++++" << std::endl;
		std::cout << e.what() << std::endl;
		std::cout << "==================================================" << std::endl;
	}

	std::cout << std::endl;
	try{
		
std::cout << std::endl; 
		std::cout << "++++++++++++ RobotomyRequestForm Constructors +++++++++++++++" << std::endl;
		RobotomyRequestForm a("RO_people");
		RobotomyRequestForm b("RO_42");
		RobotomyRequestForm c(a);
		std::cout << "+++ RO_Copy Constructor And Assignation Overload +++" << std::endl;
		c = b;
		std::cout << "+++++++++++++++++ RO_Operator Overload ++++++++++++++" << std::endl;
		std::cout << c << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception & e){
		std::cout << "++++++++++++++++++ WGradeLow ++++++++++++++++++" << std::endl;
		std::cout << e.what() << std::endl;
		std::cout << "==================================================" << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	try{ 
		std::cout << "+++++++++++++++++++ PresidentialPardonForm Allocated ++++++++++++++++++++" << std::endl;
		PR_alloc = new Bureaucrat("PR_Alloc", 5);
		PR_signer = new Bureaucrat("PR_Signer", 25);
		PR_unsigner = new Bureaucrat("PR_UnSigner", 150);
		PR_form = new PresidentialPardonForm ("PR_Scrooge");
		std::cout << "==================================================" << std::endl;
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try{
		std::cout << std::endl; 
		std::cout << "++++++++++++ PresidentialPardonForm sign Excepts +++++++++++++++" << std::endl;
		PR_unsigner->signForm(*PR_form);
		PR_form->execute(*PR_alloc);
		std::cout << std::endl;
	}
	catch (std::exception & e){
		std::cout << "++++++++++++++++++ WGradeHigh ++++++++++++++++++" << std::endl;
		std::cout << e.what() << std::endl;
		std::cout << "==================================================" << std::endl;
	}

	std::cout << std::endl;

	try{
		std::cout << std::endl; 
		std::cout << "++++++++++++ PresidentialPardonForm Execution Excepts +++++++++++++++" << std::endl;
		PR_signer->signForm(*PR_form);
		PR_form->execute(*PR_unsigner);
		std::cout << std::endl;
	}
	catch (std::exception & e){
		std::cout << "++++++++++++++++++ WGradeHigh ++++++++++++++++++" << std::endl;
		std::cout << e.what() << std::endl;
		std::cout << "==================================================" << std::endl;
	}

	std::cout << std::endl;

	try{
		std::cout << std::endl; 
		std::cout << "++++++++++++ PresidentialPardonForm Already signed +++++++++++++++" << std::endl;
		PR_signer->signForm(*PR_form);
		PR_form->execute(*PR_unsigner);
		std::cout << std::endl;
	}
	catch (std::exception & e){
		std::cout << "++++++++++++++++++ WGradeHigh ++++++++++++++++++" << std::endl;
		std::cout << e.what() << std::endl;
		std::cout << "==================================================" << std::endl;
	}

	std::cout << std::endl;

	try{
		std::cout << std::endl; 
		std::cout << "++++++++++++ PresidentialPardonForm HappyPath +++++++++++++++" << std::endl;
		PresidentialPardonForm PR_A42("42");
		PR_signer->signForm(PR_A42);
		PR_A42.execute(*PR_alloc);
		std::cout << std::endl;
	}
	catch (std::exception & e){
		std::cout << "++++++++++++++++++ WGradeHigh ++++++++++++++++++" << std::endl;
		std::cout << e.what() << std::endl;
		std::cout << "==================================================" << std::endl;
	}

	std::cout << std::endl;
	try{
		std::cout << std::endl; 
		std::cout << "++++++++++++ PresidentialPardonForm Constructors +++++++++++++++" << std::endl;
		PresidentialPardonForm a("PR_people");
		PresidentialPardonForm b("PR_42");
		PresidentialPardonForm c(a);
		std::cout << "+++ PR_Copy Constructor And Assignation Overload +++" << std::endl;
		c = b;
		std::cout << "+++++++++++++++++ PR_Operator Overload ++++++++++++++" << std::endl;
		std::cout << c << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception & e){
		std::cout << "++++++++++++++++++ WGradeLow ++++++++++++++++++" << std::endl;
		std::cout << e.what() << std::endl;
		std::cout << "==================================================" << std::endl;
	}

	std::cout << std::endl;

	delete SH_alloc;
	delete SH_signer;
	delete SH_unsigner;
	delete SH_form;
	delete RO_alloc;
	delete RO_signer;
	delete RO_unsigner;
	delete RO_form;
	delete PR_alloc;
	delete PR_signer;
	delete PR_unsigner;
	delete PR_form;

	std::cout << "++++++++++++++++++ Leaks Summary +++++++++++++++++" << std::endl;
	std::cout << std::endl;
	system("leaks Bureaucracy");
	std::cout << "==================================================" << std::endl;
}
