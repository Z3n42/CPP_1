/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:56:09 by ingonzal          #+#    #+#             */
/*   Updated: 2023/07/16 17:35:38 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _N(0){
}

Span::Span(unsigned int N) : _N(N), _times(0), _vec(new std::vector<int>()){
	/* this->_vec->resize(_N); */
}

Span::Span(Span const & src) : _N(0), _vec(0){
	*this = src;
}

Span & Span::operator=(Span const & rhs){
	if (this != &rhs){
		/* this->_N = rhs.getN(); */
		/* this->_vec = &rhs.getVec(); */
	}
	return(*this);
}

Span::~Span(void){
	delete this->_vec;
}

const unsigned int & Span::getN(void) const{
	return (this->_N);
}

const std::vector<int> & Span::getVec(void) const{
	return (*this->_vec);
}

void Span::addNumber(int N){
	std::cout << this->_times << std::endl;
	if (this->getN() > this->_times){
		this->_vec->push_back(N);
		this->_times++;
	}
	else 
		throw std::runtime_error("Vector Limit Reached");
}

std::ostream & operator<<(std::ostream & o, Span const & ref){
	std::cout << "Vector contains " << ref.getN() << " elementes max" << std::endl;
	std::cout << GREEN << "####################" << RESET << std::endl;
	  for (unsigned i=0; i < ref.getVec().size(); i++)
		std::cout << "[" << i << "]" << ref.getVec().at(i) << std::endl;
	std::cout << RED << "####################" << RESET << std::endl;
	return (o);
}
