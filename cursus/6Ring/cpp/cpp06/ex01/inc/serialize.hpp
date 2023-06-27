/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:10:53 by ingonzal          #+#    #+#             */
/*   Updated: 2023/06/27 18:11:07 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP
#include <iostream>

class Serializer{
	
	private:
		std::string _input;
		
		Serializer(void);
		Serializer(std::string input);
		Serializer(Serializer const & src);
		~Serializer(void);

		Serializer & operator=(Serializer const & rhs);

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
		};
		struct Conversions {
		  char    chars;
		  double	lf;
		};
		static void initData(Data &check);
		static void checkInput(Data &check);
		static void convert(std::string toConvert);
		static void printConversions(double lf);
		static void test();
		static void pseudoLiterals(std::string toConvert);
};


#endif
