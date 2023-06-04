/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:24:12 by ingonzal          #+#    #+#             */
/*   Updated: 2023/06/04 18:18:41 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"
#include <cstdio>

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
	ScalarConverter::Data check = {};
		if (toConvert.compare("T35T") == 0)
			ScalarConverter::test();
		else if(toConvert.compare("+inf") == 0 or toConvert.compare("-inf") == 0 or toConvert.compare("nan") == 0
				or toConvert.compare("+inff") == 0 or toConvert.compare("-inff") == 0 or toConvert.compare("nanf") == 0)
			ScalarConverter::pseudoLiterals(toConvert);
		else{
			check.str = toConvert;
			ScalarConverter::initData(check);
		}
}

void ScalarConverter::initData(Data &check){
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
}

void ScalarConverter::checkInput(Data &check){
		ScalarConverter::conversions result = {};
		if (check.chars == check.len)
			std::cout << "ALL CHAR >> " << check.str  << std::endl;
		else if (check.num == check.len and check.point < 2 and check.floa < 2 and check.signus < 2){
			if (check.floa != 0)
				std::cout << "ALL FLOAT >> " << check.str  << std::endl;
			else if (check.point != 0 and check.floa == 0)
				std::cout << "ALL DOUBLE >> " << check.str  << std::endl;
			else
				std::cout << "ALL NUM >> " << check.str  << std::endl;
		}
		else{
			std::cout << std::endl;
			std::cout << "##################################"<< std::endl;
			std::cerr << "Bad Arguments format >> " << check.str << ":" << std::endl;
			std::cout << std::endl;
			std::cout << "Num:" << check.num << std::endl;
			std::cout << "Point:" << check.point << std::endl;
			std::cout << "Signus:" << check.signus << std::endl;
			std::cout << "Float:" << check.floa << std::endl;
			std::cout << "Len:" << check.len << std::endl;
		}
}

void ScalarConverter::pseudoLiterals(std::string toConvert){
		std::string imp = "imposible";
		std::cout << "##################################"<< std::endl;
		std::cout << "Pseudo Literal :" << toConvert << std::endl;
		std::cout << std::endl;
		if (toConvert.compare("nan") == 0 or toConvert.compare("nanf") == 0){
			std::cout << "char: " << imp << std::endl;
			std::cout << "int: " << imp << std::endl;
		}
		if (toConvert.compare("nan") == 0 )
			std::cout << "float: " << "nanf" << std::endl;
		else
			std::cout << "float: " << "nan" << std::endl;
		if (toConvert.compare("nan") == 0 )
			std::cout << "double: " << toConvert << std::endl;
		else
			std::cout << "double: " << "nanf" << std::endl;
		std::cout << std::endl;
}

void ScalarConverter::test(){
	std::string input[ ]
		= {"adfs", "f", "12345", "2.2", "4.0f", "-12345", "-2.2", "-4.0f", "+3", "-adfs",
			"adfs1234", "-4,f", "2.2ff", "2.2.2f", "2..2.2f", ".2f", "-4-3", "-4f-3", "-4f3",
			"-4.f", ".f", "nan", "nanf"};

	for (int i = 0; i < sizeof(input)/sizeof(input[0]); i++)
		ScalarConverter::convert(input[i]);
}
