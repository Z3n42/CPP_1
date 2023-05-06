/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:14:23 by ingonzal          #+#    #+#             */
/*   Updated: 2023/05/06 18:12:32 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat{

	private:
		std::string  const 	_name;
		int 				_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat(void);

		Bureaucrat & operator=(Bureaucrat const & rhs);

		std::string const & getName(void) const;
		int const & getGrade(void) const;

		void setName(std::string const &name);
		void setGrade(int const &lvl, std::string const &who);
		void GradeUp(void);
		void GradeDown(void);

		void signForm(AForm &form);
		void executeForm(AForm const & form); 

		class GradeTooHighException : public std::exception {
			private:
				const char *  		_HighError;
				int					_grade;
				std::string  const 	_who;

			public:
				GradeTooHighException(void);
				GradeTooHighException(const char * error, int lvl, std::string const &name);
				int const & getGrade(void) const;
				std::string const & getName(void) const;
				virtual ~GradeTooHighException(void) throw();
				
				virtual const char* what(void) const throw();	
		};

		class GradeTooLowException : public std::exception {
			private:
				const char *  		_LowError;
				int					_grade;
				std::string  const 	_who;

			public:
				GradeTooLowException(void);
				GradeTooLowException(const char * error, int lvl, std::string const &name);
				int const & getGrade(void) const;
				std::string const & getName(void) const;
				virtual ~GradeTooLowException(void) throw();
				
				virtual const char* what(void) const throw();	
		};
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif
