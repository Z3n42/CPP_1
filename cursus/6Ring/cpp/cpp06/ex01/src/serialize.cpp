/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:13:30 by ingonzal          #+#    #+#             */
/*   Updated: 2023/06/27 18:18:52 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.hpp"
#include <iomanip>

/* orthodox canonical class form requirement */

Serializer::Serializer(void) : _input("0"){

}

Serializer::Serializer(std::string input) : _input(input){

}


Serializer::Serializer(Serializer const & src){
	*this = src;
}

Serializer::~Serializer(void){

}

Serializer & Serializer::operator=(Serializer const & rhs){
	if (this != &rhs){
		this->setInput(rhs.getInput());
	}
	return(*this);
}

/* Methods */

std::string const & Serializer::getInput(void) const{
	return (this->_input);
}

void Serializer::setInput(std::string const &input){
	this->_input = input;
}

void Serializer::serialize(std::string toserialize){
	Serializer::Data check = {};
		if (toserialize.compare("T35T") == 0)
			Serializer::test();
		else if(toserialize.compare("+inf") == 0 or toserialize.compare("-inf") == 0 or toserialize.compare("nan") == 0
				or toserialize.compare("+inff") == 0 or toserialize.compare("-inff") == 0 or toserialize.compare("nanf") == 0)
			Serializer::pseudoLiterals(toserialize);
		else{
			check.str = toserialize;
			Serializer::initData(check);
		}
}

void Serializer::initData(Data &check){
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
	Serializer::checkInput(check);
}

void Serializer::checkInput(Data &check){
		Serializer::Conversions result = {};
		if (check.chars == check.len){
			/* std::cout << "ALL CHAR >> " << check.str  << std::endl; */
			sscanf(check.str.data(), "%s", &result.chars);
			if (check.str.length() != 1)
				std::cerr << "Bad Arguments format >> " << check.str << std::endl;
			else
				Serializer::printConversions(result.chars);
		}
		else if (check.num == check.len and check.point < 2 and check.floa < 2 and check.signus < 2){
			/* if (check.floa != 0) */
			/* 	std::cout << "ALL FLOAT >> " << check.str  << std::endl; */
			/* else if (check.point != 0 and check.floa == 0) */
			/* 	std::cout << "ALL DOUBLE >> " << check.str  << std::endl; */
			/* else */
			/* 	std::cout << "ALL NUM >> " << check.str  << std::endl; */
			/* std::cout << std::endl; */
			sscanf(check.str.data(), "%lf", &result.lf);
			Serializer::printConversions(result.lf);
		}
		else
			std::cerr << "Bad Arguments format >> " << check.str << std::endl;
		/* std::cout << std::endl; */
}

void Serializer::pseudoLiterals(std::string toserialize){
		std::cout << "char: imposible" << std::endl;
		std::cout << "int: imposible" << std::endl;
		if (toserialize[toserialize.length() - 1] == 'f' and (toserialize[toserialize.length() - 2] == 'f' or toserialize[0] == 'n'))
			std::cout << "float: " << toserialize << std::endl;
		else
			std::cout << "float: " << toserialize << "f" << std::endl;
		if (toserialize[toserialize.length() - 1] == 'f'){
			if (toserialize[toserialize.length() - 2] == 'f' or toserialize[0] == 'n')
				std::cout << "double: " << toserialize.erase(toserialize.length() - 1) << std::endl;
			else
				std::cout << "double: " << toserialize << std::endl;
		}
		else
			std::cout << "double: " << toserialize << std::endl;
}

void Serializer::printConversions(double lf){
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

void Serializer::test(){
	std::string input[ ]
		= { "0", "nan", "nanf", "+inf", "+inff", "-inf", "-inff", "42.0f", "f", "102.3", 
			"2.2", "4.1f", "-12345", "-2.2", "-4.1f", "+3", "+4.1f",  "2147483647", "-2147483648", "2147483648",
			"-2147483649", "33333333333333333333333333333333333333333333333333333333333333333333333333333333333333333",
			"adfs", "adfs1234", "-4,f", "2.2ff", "2.2.2f", "2..2.2f", ".2f", "-4-3", "-4f-3", "-4f3",
			"-4.f", ".f"};

	std::cout << std::endl;
	std::cout << "\33[32m" << "############RIGHT_INPUT############" << std::endl;
	for (int i = 0; i < sizeof(input)/sizeof(input[0]); i++){
		std::cout  << "\33[39m" << "Test Input -> " << input[i] << std::endl;
		std::cout << std::endl;
		Serializer::serialize(input[i]);
		if (i > 20)
			std::cout << "\33[31m" << "############WRONG_INPUT############" << std::endl;
		else
			std::cout << "\33[32m" << "############RIGHT_INPUT############" << std::endl;
	}
}
