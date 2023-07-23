/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:56:09 by ingonzal          #+#    #+#             */
/*   Updated: 2023/07/23 17:45:14 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <cstdlib>

Span::Span(void) : _N(0){
}

Span::Span(unsigned int N) : _N(N), _vec(new std::vector<int>()){
		this->_vec->reserve(_N);
}

Span::Span(Span const & src){
	*this = src;
}

Span & Span::operator=(Span const & rhs){
	if (this != &rhs){
		this->_N = rhs.getN();
		/* delete this->_vec; */
		this->_vec = new std::vector<int>();
	  	for (unsigned i=0; i < rhs.getVec().size(); i++){
			/* std::cout << rhs.getVec().at(i) << std::endl; */
			this->_vec->push_back(rhs.getVec().at(i));
		}
	}
	return(*this);
}

Span::~Span(void){
	delete this->_vec;
}

const unsigned int & Span::getN(void) const{
	return (this->_N);
}

std::vector<int> & Span::getVec(void) const{
	return (*this->_vec);
}

void Span::addNumber(int N){
	/* std::cout << this->getVec().size() << std::endl; */
	if (this->getN() > this->getVec().size())
		this->_vec->push_back(N);
	else 
		throw std::runtime_error("Vector Limit Reached");
}

int Span::longestSpan(){
	if(this->_vec->size() < 2) 
		throw std::runtime_error("Not enough vector size");
	/* std::cout << std::endl << "MAX => " << *std::max_element(this->_vec->begin(), this->_vec->end()) << std::endl; */
	/* std::cout << std::endl << "MIN => " << *std::min_element(this->_vec->begin(), this->_vec->end()) << std::endl; */
	return (*std::max_element(this->_vec->begin(), this->_vec->end()) - 
			*std::min_element(this->_vec->begin(), this->_vec->end()));
	/* int max; */
	/* int min; */
	/* max = this->_vec->at(0); */ 
	/* min = this->_vec->at(0); */ 
	/* for (unsigned i=0; i < this->_vec->size(); i++){ */
	/* 	if (this->_vec->at(i) > max) */	
	/* 		max = this->_vec->at(i); */
	/* 	if (this->_vec->at(i) < min) */	
	/* 		min = this->_vec->at(i); */
	/* } */
	/* return(min - max); */
}

int Span::shortestSpan(){
	if(this->_vec->size() < 2) 
		throw std::runtime_error("Not enough vector size");
	int min;
	min = this->longestSpan(); 
	std::sort(this->_vec->begin(), this->_vec->end());
	for (unsigned i=0; i < this->_vec->size(); i++){
		if (i and abs(this->_vec->at(i) - this->_vec->at(i - 1)) < min and
				abs(this->_vec->at(i) - this->_vec->at(i - 1)) != 0)
			min = abs(this->_vec->at(i) - this->_vec->at(i - 1));
		/* for (unsigned j=i+1; j < this->_vec->size(); j++){ */
		/* 	if (abs(this->_vec->at(i) - this->_vec->at(j)) < min and */
		/* 			abs(this->_vec->at(i) - this->_vec->at(j)) != 0) */
		/* 		min = abs(this->_vec->at(i) - this->_vec->at(j)); */
		/* } */
	}
	return min;
}

int RandomNumber(){ 
	return (std::rand());
}

void Span::generator(){
		std::srand(unsigned( std::time(NULL)));
		delete this->_vec;
		this->_vec = new std::vector<int>(_N, 42);
		std::generate(this->_vec->begin(), this->_vec->end(), RandomNumber);
}

std::ostream & operator<<(std::ostream & o, Span const & ref){
	std::cout << "Vector capacity " << ref.getN() << " elementes max" << std::endl;
	std::cout << GREEN << "####################" << RESET << std::endl;
	  for (unsigned i=0; i < ref.getVec().size(); i++)
		std::cout << "[" << i << "]" << ref.getVec().at(i) << std::endl;
	std::cout << RED << "####################" << RESET << std::endl;
	return (o);
}

			/* std::cout << "{" << i << "}" << "{" << j << "}" << this->_vec->at(i) << "-" << this->_vec->at(j) << "=" << min << std::endl; */
