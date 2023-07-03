/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:13:30 by ingonzal          #+#    #+#             */
/*   Updated: 2023/07/03 17:58:24 by ingonzal         ###   ########.fr       */
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

	return (reinterpret_cast<uintptr_t>(ptr));
}

Serializer::Data* Serializer::deserialize(uintptr_t raw){
	Data *result;

	result = reinterpret_cast<Data *>(raw);
	return (result);
}

std::ostream & operator<<(std::ostream & o, Serializer::Data const & rhs){
    o << "Num: " << rhs.num << std::endl << "Chars: " << rhs.chars << std::endl;
	return (o);
}

