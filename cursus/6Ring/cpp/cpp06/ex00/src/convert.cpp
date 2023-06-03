/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:24:12 by ingonzal          #+#    #+#             */
/*   Updated: 2023/06/03 20:18:29 by ingonzal         ###   ########.fr       */
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

void ScalarConverter::initData(int argc, char** argv){
	if (argc == 2){
		ScalarConverter::Data check = {};
		check.str = static_cast<std::string>(argv[1]);
		check.len = check.str.length(); 

		while(check.count <= check.len){
			if (check.str[check.count] == 'f' and check.str[check.count + 1] == '\0' and std::isdigit(check.str[check.count - 1])){
				check.num++;
				check.floa++;
			}
			else if (std::isdigit(check.str[check.count]))
				check.num++;
			else if (check.str[check.count] == '.' and std::isdigit(check.str[check.count - 1]) and std::isdigit(check.str[check.count + 1])){
				check.num++;
				check.point++;
			}
			else if ((check.str[check.count] == '-' or check.str[check.count] == '+')  and std::isdigit(check.str[check.count + 1])){
				check.num++;
				check.signus++;
			}
			else if (std::isalpha(check.str[check.count]))
				check.chars++;
			else 
				break;
			check.count++;
		}
		ScalarConverter::checkInput(check);
		ScalarConverter::convert(check.str);
	}
	else
		std::cout << "Bad Arguments amount" << std::endl;
}

void ScalarConverter::checkInput(Data &check){
		if (check.chars == check.len)
			std::cout << "ALL CHAR" << std::endl;
		else if (check.num == check.len and check.point < 2 and check.floa < 2 and check.signus < 2){
			if (check.floa != 0)
				std::cout << "ALL FLOAT" << std::endl;
			else if (check.point != 0 and check.floa == 0)
				std::cout << "ALL DOUBLE" << std::endl;
			else
				std::cout << "ALL NUM" << std::endl;
		}
		else{
			std::cout << "Num:" << check.num << std::endl;
			std::cout << "Point:" << check.point << std::endl;
			std::cout << "Signus:" << check.signus << std::endl;
			std::cout << "Float:" << check.floa << std::endl;
			std::cout << "Len:" << check.len << std::endl;
			std::cout << "Bad Arguments" << std::endl;
		}
}
