/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:24:12 by ingonzal          #+#    #+#             */
/*   Updated: 2023/06/10 19:15:16 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"
#include <cstdio>
#include <iomanip>
#include <climits>
#include <cfloat>

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
		ScalarConverter::Conversions result = {};
		if (check.chars == check.len){
			std::cout << "ALL CHAR >> " << check.str  << std::endl;
			result.chars = check.str;
			std::cout << result.chars << std::endl;
			std::cout << typeid(result.chars).name() << std::endl;
			}
		else if (check.num == check.len and check.point < 2 and check.floa < 2 and check.signus < 2){
			if (check.floa != 0){
				std::cout << "ALL FLOAT >> " << check.str  << std::endl;
				sscanf(check.str.data(), "%Lf", &result.f);
				std::cout << result.f << std::endl;
				std::cout << typeid(result.f).name() << std::endl;
			}
			else if (check.point != 0 and check.floa == 0){
				std::cout << "ALL DOUBLE >> " << check.str  << std::endl;
				sscanf(check.str.data(), "%Lf", &result.lf);
				std::cout << result.lf << std::endl;
				std::cout << typeid(result.lf).name() << std::endl;
			}
			else{
				std::cout << "ALL NUM >> " << check.str  << std::endl;
				sscanf(check.str.data(), "%lld", &result.d);
				std::cout << result.d << std::endl;
				std::cout << typeid(result.d).name() << std::endl;
				ScalarConverter::printConversions(result.d);
			}
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
		if (toConvert.compare("nan") == 0)
			std::cout << "float: " << "nanf" << std::endl;
		else
			std::cout << "float: " << "nan" << std::endl;
		if (toConvert.compare("nan") == 0)
			std::cout << "double: " << toConvert << std::endl;
		else
			std::cout << "double: " << "nanf" << std::endl;
		std::cout << std::endl;
}

void ScalarConverter::printConversions(long long int d){
		std::cout << std::endl;
		std::cout << "##################################" << std::endl;
		std::cout << std::fixed;
		if (std::isalpha(d))
			std::cout << "char: " << static_cast<char>(d) << std::endl;
		else
			std::cout << "char: " << "Non displayable" << std::endl;
		if (d > INT_MAX or d < INT_MIN)
			std::cout << "int: " << "impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(d) << std::endl;
		if (d != 0 and (d == LLONG_MAX or d == LLONG_MIN)){
			std::cout << "float: " << "impossible" << std::endl;
			std::cout << "double: " << "impossible" << std::endl;
			}
		else{
			std::cout << "float: " << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
			std::cout << "double: "<< std::setprecision(1) << static_cast<double>(d) << std::endl;
			}
}

void ScalarConverter::test(){
	std::string input[ ]
		= {"adfs", "f", "12345", "2.2", "4.1f", "-12345", "-2.2", "-4.1f", "+3", "-adfs",
			"adfs1234", "-4,f", "2.2ff", "2.2.2f", "2..2.2f", ".2f", "-4-3", "-4f-3", "-4f3",
			"-4.f", ".f","2147483648", "-2147483649" , "nan", "nanf"};

	for (int i = 0; i < sizeof(input)/sizeof(input[0]); i++)
		ScalarConverter::convert(input[i]);
}

