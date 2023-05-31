/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:24:12 by ingonzal          #+#    #+#             */
/*   Updated: 2023/05/27 14:47:55 by ingonzal         ###   ########.fr       */
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
