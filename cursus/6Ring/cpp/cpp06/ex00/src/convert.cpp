/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:24:12 by ingonzal          #+#    #+#             */
/*   Updated: 2023/06/02 19:37:47 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

ScalarConverter::ScalarConverter(void) : _input("0"){

}

ScalarConverter::ScalarConverter(std::string input) : _input(input){

}


ScalarConverter::ScalarConverter(ScalarConverter const & src){
	*this = src;
}

ScalarConverter::~ScalarConverter(void){

}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs){
	if (this != &rhs){
		this->setInput(rhs.getInput());
	}
	return(*this);
}

std::string const & ScalarConverter::getInput(void) const{
	return (this->_input);
}

void ScalarConverter::setInput(std::string const &input){
	this->_input = input;
}

void ScalarConverter::convert(std::string toConvert){
	std::cout << toConvert << std::endl;
}

void ScalarConverter::checkInput(int i, int j, int k, int f, int m, int len){
		if (i == len)
			std::cout << "ALL CHAR" << std::endl;
		else if (j == len and k < 2 and f < 2 and m < 2){
			if (f != 0)
				std::cout << "ALL FLOAT" << std::endl;
			else if (k != 0 and f == 0)
				std::cout << "ALL DOUBLE" << std::endl;
			else
				std::cout << "ALL NUM" << std::endl;
		}
		else
			std::cout << "Bad Arguments" << std::endl;
}
