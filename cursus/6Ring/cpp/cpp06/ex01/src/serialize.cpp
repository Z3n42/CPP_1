/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:13:30 by ingonzal          #+#    #+#             */
/*   Updated: 2023/06/27 19:32:49 by ingonzal         ###   ########.fr       */
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

uintptr_t Serializer::serialize(Data* ptr){
	uintptr_t	result;

	re
}

Data* Serializer::sdeserialize(uintptr_t raw){

}
}
