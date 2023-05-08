/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:41:34 by ingonzal          #+#    #+#             */
/*   Updated: 2023/05/07 21:07:37 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHUBBERRYCREATIONFORM_HPP
# define SHUBBERRYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
	
	private:
		std::string _target;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		virtual ~ShrubberyCreationForm(void);

		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);


		std::string const &getTarget(void) const;
		virtual void execute(Bureaucrat const & executor) const;
};

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & rhs);

#endif
