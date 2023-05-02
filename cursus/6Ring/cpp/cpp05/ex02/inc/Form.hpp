/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:33:21 by ingonzal          #+#    #+#             */
/*   Updated: 2023/05/02 15:12:57 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{

	private:
		std::string  const 	_name;
		int const 			_Wgrade;
		int const 			_Xgrade;
		bool				_sign;

	public:
		Form(void);
		Form(std::string const name, int const Wgrade, int const Xgrade, bool sign = false);
		Form(Form const & src);
		~Form(void);

		Form & operator=(Form const & rhs);

		std::string const & getName(void) const;
		int const & getXgrade(void) const;
		int const & getWgrade(void) const;
		int const  getSign(void) const;

		void setWgrade(int const &Wlvl, std::string const &who);
		void setXgrade(int const &Xlvl, std::string const &who);

		void beSigned(Bureaucrat bureaucrat);
		void beSigned(Bureaucrat *bureaucrat);


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
