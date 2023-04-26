/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:33:21 by ingonzal          #+#    #+#             */
/*   Updated: 2023/04/26 19:58:22 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <stdexcept>

class Form{

	private:
		std::string  const 	_name;
		bool				_signed;
		int const 			_Wgrade;
		int const 			_Xgrade;

	public:
		Form(void);
		Form(std::string const name, int grade);
		Form(Form const & src);
		~Form(void);

		Form & operator=(Form const & rhs);

		std::string const & getName(void) const;
		int const & getGrade(void) const;

		void setgrade(int const &lvl, std::string const &who);
		void beSigned(Bureaucrat bureucrat);

		void GradeUp(void);
		void GradeDown(void);

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

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif
