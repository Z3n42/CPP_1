/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:14:23 by ingonzal          #+#    #+#             */
/*   Updated: 2023/04/08 19:56:39 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat{

	private:
		std::string const 	_name;
		int 				_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat(void);

		Bureaucrat & operator=(Bureaucrat const & rhs);

		std::string const & getName(void) const;
		int const & getGrade(void) const;

		void setGradeUp();
		void setGradeDown();

		class GradeTooHighException : public std::exception {
			private:
				std::string _HighError;

			public:
				GradeTooHighException(std::string error);
				virtual ~GradeTooHighException(void) throw();
				
				virtual const char* what(void) const throw();	
		};

		class GradeTooLowException : public std ::exception {
			private:
				std::string _LowError;

			public:
				GradeTooLowException(std::string error);
				virtual ~GradeTooLowException(void) throw();
				
				virtual const char* what(void) const throw();	
		};
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif
