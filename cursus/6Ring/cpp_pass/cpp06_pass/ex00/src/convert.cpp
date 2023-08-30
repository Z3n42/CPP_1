/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:24:12 by ingonzal          #+#    #+#             */
/*   Updated: 2023/07/04 16:33:55 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"
#include <iomanip>
#include <float.h>

/* orthodox canonical class form requirement */

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
		this->_input = rhs._input;
	}
	return(*this);
}

/* Methods */

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
			/* std::cout << "ALL CHAR >> " << check.str  << std::endl; */
			sscanf(check.str.data(), "%s", &result.chars);
			if (check.str.length() != 1)
				std::cerr << "Bad Arguments format >> " << check.str << std::endl;
			else
				ScalarConverter::printConversions(result.chars);
		}
		else if (check.num == check.len and check.point < 2 and check.floa < 2 and check.signus < 2){
			if (check.floa != 0){
				sscanf(check.str.data(), "%f", &result.f);
				ScalarConverter::printConversions(result.f);
				/* std::cout << "ALL FLOAT >> " << check.str  << std::endl; */
			}
			else if (check.point != 0 and check.floa == 0){
				sscanf(check.str.data(), "%lf", &result.lf);
				ScalarConverter::printConversions(result.lf);
				/* std::cout << "ALL DOUBLE >> " << check.str  << std::endl; */
			}
			else{
				sscanf(check.str.data(), "%lf", &result.lf);
				sscanf(check.str.data(), "%d", &result.d);
				if (result.lf > INT_MAX or result.lf < INT_MIN)
					std::cerr << "INT LIMIT OVERLOAD >> " << check.str << std::endl;
				else
					ScalarConverter::printConversions(result.d);
				/* std::cout << "ALL NUM >> " << check.str  << std::endl; */
			}
		}
		else
			std::cerr << "Bad Arguments format >> " << check.str << std::endl;
}

void ScalarConverter::pseudoLiterals(std::string toConvert){
		std::cout << "char: imposible" << std::endl;
		std::cout << "int: imposible" << std::endl;
		if (toConvert[toConvert.length() - 1] == 'f' and (toConvert[toConvert.length() - 2] == 'f' or toConvert[0] == 'n'))
			std::cout << "float: " << toConvert << std::endl;
		else
			std::cout << "float: " << toConvert << "f" << std::endl;
		if (toConvert[toConvert.length() - 1] == 'f'){
			if (toConvert[toConvert.length() - 2] == 'f' or toConvert[0] == 'n')
				std::cout << "double: " << toConvert.erase(toConvert.length() - 1) << std::endl;
			else
				std::cout << "double: " << toConvert << std::endl;
		}
		else
			std::cout << "double: " << toConvert << std::endl;
}

void ScalarConverter::printConversions(int d){
		/* std::cout << "INT" << std::endl; */
		std::cout << std::scientific;
		if (std::isprint(d))
			std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
		else if (d < 0 or d > 127)
			std::cout << "char: " << "impossible" << std::endl;
		else
			std::cout << "char: " << "Non displayable" << std::endl;
		if (d > INT_MAX or d < INT_MIN)
			std::cout << "int: " << "impossible" << std::endl;
		else{
			std::cout << std::fixed;
			std::cout << "int: " << static_cast<int>(d) << std::endl;
		}
		std::cout << "float: " << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: "<< std::setprecision(1) << static_cast<double>(d) << std::endl;
}

void ScalarConverter::printConversions(float f){
		/* std::cout << "FLOAT" << std::endl; */
		std::cout << std::scientific;
		if (std::isprint(f))
			std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
		else if (f < 0 or f > 127)
			std::cout << "char: " << "impossible" << std::endl;
		else
			std::cout << "char: " << "Non displayable" << std::endl;
		if (f > INT_MAX or f < INT_MIN)
			std::cout << "int: " << "impossible" << std::endl;
		else{
			std::cout << std::fixed;
			std::cout << "int: " << static_cast<int>(f) << std::endl;
		}
		std::cout << "float: " << std::setprecision(1) << static_cast<float>(f) << "f" << std::endl;
		std::cout << "double: "<< std::setprecision(1) << static_cast<double>(f) << std::endl;
}

void ScalarConverter::printConversions(double lf){
		/* std::cout << "DOUBLE" << std::endl; */
		std::cout << std::scientific;
		if (std::isprint(lf))
			std::cout << "char: '" << static_cast<char>(lf) << "'" << std::endl;
		else if (lf < 0 or lf > 127)
			std::cout << "char: " << "impossible" << std::endl;
		else
			std::cout << "char: " << "Non displayable" << std::endl;
		if (lf > INT_MAX or lf < INT_MIN)
			std::cout << "int: " << "impossible" << std::endl;
		else{
			std::cout << std::fixed;
			std::cout << "int: " << static_cast<int>(lf) << std::endl;
		}
		std::cout << "float: " << std::setprecision(1) << static_cast<float>(lf) << "f" << std::endl;
		std::cout << "double: "<< std::setprecision(1) << static_cast<double>(lf) << std::endl;
}

void ScalarConverter::test(){
	std::string input[ ]
		= { "0", "nan", "nanf", "+inf", "+inff", "-inf", "-inff", "42.0f", "f", "102.3", 
			"2.2", "4.1f", "-12345", "-2.2", "-4.1f", "+3", "+4.1f",  "2147483647", "-2147483648",
			"33333333333333333333333333333333333333333333333333333333333333333333333333333333333333333.0",
			"adfs", "adfs1234", "-4,f", "2.2ff", "2.2.2f", "2..2.2f", ".2f", "-4-3", "-4f-3", "-4f3",
			"-4.f", ".f", "2147483648", "-2147483649"};

	std::cout << std::endl;
	std::cout << "\33[32m" << "############RIGHT_INPUT############" << std::endl;
	for (int i = 0; i < sizeof(input)/sizeof(input[0]); i++){
		std::cout  << "\33[39m" << "Test Input -> " << input[i] << std::endl;
		std::cout << std::endl;
		ScalarConverter::convert(input[i]);
		if (i > 18)
			std::cout << "\33[31m" << "############WRONG_INPUT############" << std::endl;
		else
			std::cout << "\33[32m" << "############RIGHT_INPUT############" << std::endl;
	}
}
