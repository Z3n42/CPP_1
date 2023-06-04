/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:24:36 by ingonzal          #+#    #+#             */
/*   Updated: 2023/06/04 17:27:27 by ingonzal         ###   ########.fr       */
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
		struct Data {
		  std::string str;
		  int    count;
		  int    chars;
		  int    num;
		  int    point;
		  int    signus;
		  int    floa;
		  int    len;
		  int    d;
		  float  f;
		  double lf;
		};
		struct conversions {
		  std::string chars;
		  int    d;
		  float  f;
		  double lf;
		};
		static void initData(Data &check);
		static void checkInput(Data &check);
		static void convert(std::string toConvert);
		static void test();
		static void pseudoLiterals(std::string toConvert);
};


#endif
