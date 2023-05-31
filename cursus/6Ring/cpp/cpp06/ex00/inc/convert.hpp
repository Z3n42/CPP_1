/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:24:36 by ingonzal          #+#    #+#             */
/*   Updated: 2023/05/27 14:47:59 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP
#include <iostream>

class ScalarConverter{
	
	private:
		std::string _input;
		
		ScalarConverter(void);
		ScalarConverter(std::string input);
		ScalarConverter(ScalarConverter const & src);
		~ScalarConverter(void);

		ScalarConverter & operator=(ScalarConverter const & rhs);

		std::string const & getInput(void) const;
		void setInput(std::string const &input);

	public:
		static void convert(std::string toConvert);
};

#endif
