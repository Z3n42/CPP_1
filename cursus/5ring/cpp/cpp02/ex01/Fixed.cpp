/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:17:17 by ingonzal          #+#    #+#             */
/*   Updated: 2022/06/10 13:57:32 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : _in(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n){
	std::cout << "Int constructor called" << std::endl;
	setRawBits(n << this->_fracbit);
}

Fixed::Fixed(float const n){
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(n * (1 << this->_fracbit)));
}
	/* Otras Opciones */
	/* setRawBits(roundf(n * 256)); */
	/* this->_in = round(n * 256); */
	/* Otra opcion menos precisa */
	/* setRawBits(n * (1 << this->_fracbit)); */

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}


Fixed::Fixed(const Fixed &src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &rhs){
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_in = rhs.getRawBits();
	return *this;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs){
	o << rhs.toFloat();
	return o;
}

float Fixed::toFloat(void) const{
	float f;

	f = (float)this->_in / (1 << this->_fracbit);
	return f;
}
	/* Otras opciones */
	/* f = (float)this->getRawBits() / (1 << this->_fracbit); */
	/* f = ((float)this->_in / 256); */

int Fixed::toInt(void) const{

	return (this->getRawBits() >> this->_fracbit);
	/* Otra posibilidad */
	/* return (this->_in >> this->_fracbit); */
	/* return (this->_in / 256); */
}

int Fixed::getRawBits(void) const{
	/* std::cout << "getRawBits member function called" << std::endl; */
	return this->_in;
}

void Fixed::setRawBits(int const raw){
	/* std::cout << "setRawBits member function called" << std::endl; */
	this->_in = raw;
}
