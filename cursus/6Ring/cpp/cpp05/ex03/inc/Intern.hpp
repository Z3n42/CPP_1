/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:12:34 by ingonzal          #+#    #+#             */
/*   Updated: 2023/05/13 16:52:27 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern{

	public:
		Intern(void);
		Intern(Intern const & src);
		~Intern(void);

		Intern & operator=(Intern const & rhs);

		AForm* makeForm(std::string formName, std::string target);	

		class Exception : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
