/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:41:34 by ingonzal          #+#    #+#             */
/*   Updated: 2023/05/04 11:58:25 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHUBBERRYCREATIONFORM_HPP
# define SHUBBERRYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
	
	private:
		std::string target

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string const name, int const Wgrade = 147, int const Xgrade = 135, bool sign = false);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		virtual ~ShrubberyCreationForm(void);

		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);

		virtual void execute(Bureaucrat const & executor) const;
}

#endif
